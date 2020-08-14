/**
 * @file my_polygon.hpp
 * @author Linming Pan
 * @date 10.8.2020
 * @brief Polygon DrawItem
 *
 */

#ifndef MY_POLYGON_HPP
#define MY_POLYGON_HPP

#include <QPainterPath>
#include <my_space/my_draw_item.hpp>

namespace my_space
{
class MyPolygon : public MyDrawItem
{
private:
    qreal theta_ = 0;  // in degree
    QPainterPath polygon_;

public:
    MyPolygon();

    MyPolygon(const QPolygonF& polygon, qreal theta);

    void updatePolygon(const QPolygonF& polygon, qreal theta);

    void paint(QPainter* painter, QPaintEvent* event, double size_scale = 1);

    bool contains(const QPointF& point) const;

private:
    void update(const QPolygonF& polygon);
};
}  // namespace my_space

#endif  // MY_POLYGON_HPP
