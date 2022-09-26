#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Entry fn_entry;
  Gtk::Entry ln_entry;
  Gtk::Button button;
  Gtk::Label fn_label;
  Gtk::Label ln_label;
  Gtk::Label name_label;

  Window() {
    set_title("Exercise 4");
    button.set_sensitive(false);
    button.set_label("Combine names");

    fn_label.set_text("First name");
    vbox.pack_start(fn_label);  //Add the widget label to vbox
    vbox.pack_start(fn_entry);  //Add the widget entry to vbox

    ln_label.set_text("Last name");
    vbox.pack_start(ln_label);  //Add the widget label to vbox
    vbox.pack_start(ln_entry);  //Add the widget entry to vbox

    vbox.pack_start(button); //Add the widget button to vbox
    vbox.pack_start(name_label);  //Add the widget label to vbox

    add(vbox);  //Add vbox to window
    show_all(); //Show all widgets

    auto enable_button_on_non_empty_entries = [this]() {
      if (fn_entry.get_text() != "" && ln_entry.get_text() != "") {
        button.set_sensitive(true);
      } else {
        button.set_sensitive(false);
      }
    };

    fn_entry.signal_changed().connect(enable_button_on_non_empty_entries);
    ln_entry.signal_changed().connect(enable_button_on_non_empty_entries);

    button.signal_clicked().connect([this]() {
      name_label.set_text("Full name: " + fn_entry.get_text() + " " + ln_entry.get_text());
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  gtk_main.run(window);
}
