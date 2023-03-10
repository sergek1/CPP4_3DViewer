#ifndef CPP4_3DVIEWER_V2_0_0_SRC_APP_VIEW_VIEWSETTINGS_H_
#define CPP4_3DVIEWER_V2_0_0_SRC_APP_VIEW_VIEWSETTINGS_H_

#include <QColorDialog>
#include <fstream>

namespace s21 {

class ViewSettings {
 public:
  ViewSettings(const ViewSettings &) = delete;
  ViewSettings &operator=(const ViewSettings &) = delete;
  static ViewSettings &GetInstance() {
    static ViewSettings instance;
    return instance;
  }
  int get_line_type() { return line_type_; }
  int get_vertex_type() { return vertex_type_; }
  int get_projection_type() { return projection_type_; }
  float get_line_width() { return line_width_; }
  float get_vertex_size() { return vertex_size_; }
  QColor &get_color_back() { return color_back_; }
  QColor &get_color_line() { return color_line_; }
  QColor &get_color_vertex() { return color_vertex_; }
  void set_line_type(int line_type) { line_type_ = line_type; }
  void set_vertex_type(int vertex_type) { vertex_type_ = vertex_type; }
  void set_projection_type(int projection_type) {
    projection_type_ = projection_type;
  }
  void set_line_width(float line_width) { line_width_ = line_width; }
  void set_vertex_size(float vertex_size) { vertex_size_ = vertex_size; }
  void set_color_back(QColor color_back) { color_back_ = color_back; }
  void set_color_line(QColor color_line) { color_line_ = color_line; }
  void set_color_vertex(QColor color_vertex) { color_vertex_ = color_vertex; }
  void ReadViewSettings();

 private:
  ViewSettings(){};
  ~ViewSettings() { SaveViewSettings(); }
  void SaveViewSettings();
  int line_type_{}, vertex_type_{}, projection_type_{};
  float line_width_ = 1, vertex_size_ = 1;
  QColor color_back_ = QColor(0, 0, 0), color_line_ = QColor(255, 255, 255),
         color_vertex_ = QColor(255, 255, 255);
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_0_SRC_APP_VIEW_VIEWSETTINGS_H_
