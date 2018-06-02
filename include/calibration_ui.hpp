#ifndef CALIBRATION_UI_HPP
#define CALIBRATION_UI_HPP

#include <gtkmm/builder.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/stack.h>
#include <gtkmm/window.h>

class CalibrationUi : public Gtk::Window {
   public:
    CalibrationUi(BaseObjectType* cobject,
                  const Glib::RefPtr<Gtk::Builder>& refBuilder);

    virtual ~CalibrationUi();

    static std::unique_ptr<CalibrationUi> create();

    void set_source_monitor_name(std::string name);

   private:
    Glib::RefPtr<Gtk::Builder> builder;

    Gtk::Stack* stack;
    Gtk::DrawingArea* spectrum;

    sigc::connection spectrum_connection;

    bool mouse_inside;
    double mouse_intensity, mouse_freq;
    std::vector<float> spectrum_mag;

    void on_new_spectrum(const std::vector<float>& magnitudes);

    bool on_spectrum_draw(const Cairo::RefPtr<Cairo::Context>& ctx);

    bool on_spectrum_enter_notify_event(GdkEventCrossing* event);

    bool on_spectrum_leave_notify_event(GdkEventCrossing* event);

    bool on_spectrum_motion_notify_event(GdkEventMotion* event);

    void on_stack_visible_child_changed();
};

#endif