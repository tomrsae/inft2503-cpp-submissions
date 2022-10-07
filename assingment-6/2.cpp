#include <boost/asio.hpp>
#include <iostream>
#include <fstream>

using namespace boost;

class SimpleHTTPServer {
    struct Connection {
        asio::ip::tcp::socket socket;
        Connection(boost::asio::io_service &io_service) : socket(io_service) {}
    };

    asio::io_service io_service;

    asio::ip::tcp::endpoint endpoint;
    asio::ip::tcp::acceptor acceptor;

    std::string get_html_file_contents(std::string path) {
        if (path == "/") path = "/index";
        if (path.find(".html") == std::string::npos) path += ".html";

        std::ifstream file("../public" + path);
        file.exceptions(std::ifstream::failbit);
        std::string file_contents;

        std::string buffer;
        while (getline(file, buffer)) {
            file_contents += buffer;
            if (file.eof()) break;
        }

        return file_contents;
    }

    std::string resolve_path(std::string path) {
        std::string http_response = "HTTP/1.1 ";

        try {
            std::string html_body = get_html_file_contents(path);
            http_response += "200 OK\r\n\r\n"
                        + html_body;
        } catch (const std::ios::failure& e) {
            std::cout << "Encountered IO exception: " << e.what() << "\n";
            http_response += "404 NOT FOUND";
        }

        http_response += "\r\n";
        return http_response;
    }

    void handle_request(std::shared_ptr<Connection> connection) {
        auto read_buffer = std::make_shared<boost::asio::streambuf>();
            async_read_until(connection->socket, *read_buffer, "\r\n",
                [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
            if (!ec) {
                std::istream read_stream(read_buffer.get());
                std::string message;
                getline(read_stream, message);
                message.pop_back();

                size_t http_start_pos;
                if ((http_start_pos = message.find("HTTP")) == std::string::npos
                    || message.find("GET") == std::string::npos) {
                    return;
                }

                size_t path_start_pos = message.find("/");
                std::string requested_path = message.substr(path_start_pos, http_start_pos - path_start_pos - 1);
                
                std::cout << "Received incoming GET request for path \"" << requested_path << "\"\n";

                std::string response = resolve_path(requested_path);

                auto write_buffer = std::make_shared<boost::asio::streambuf>();
                std::ostream write_stream(write_buffer.get());
                write_stream << response;

                async_write(connection->socket, *write_buffer,
                    [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
                    // If not error:
                    //if (!ec) handle_request(connection);
                });
            }
        });
    }

  void accept() {
    // The (client) connection is added to the lambda parameter and handle_request
    // in order to keep the object alive for as long as it is needed.
    auto connection = std::make_shared<Connection>(io_service);
    
    // Accepts a new (client) connection. On connection, immediately start accepting a new connection 
    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
      accept();
      // If not error:
      if (!ec) {
        handle_request(connection);
      }
    });
  }

public:
    SimpleHTTPServer() : endpoint(asio::ip::tcp::v4(), 8080), acceptor(io_service, endpoint) {}

    void start() {
        accept();

        io_service.run();
    }
};

int main() {
  SimpleHTTPServer server;

  std::cout << "Starting simple HTTP server" << std::endl
       << "Connect on a browser by visiting http://localhost:8080." << std::endl;

  server.start();
}
