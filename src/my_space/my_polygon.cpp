/**
 * @file my_polygon.cpp
 * @author Linming Pan
 * @date 10.8.2020
 * @brief
 *
 */

#include <my_space/my_polygon.hpp>

namespace my_space
{
MyPolygon::MyPolygon()
    : MyDrawItem("", "poly")
{
    update(QPolygon());
}

MyPolygon::MyPolygon(const QPolygonF& polygon, qreal theta)
    : MyDrawItem("", "poly")
    , theta_(theta)
{
    update(polygon);
}

void MyPolygon::updatePolygon(const QPolygonF& polygon, qreal theta)
{
    theta_ = theta;
    update(polygon);
}

void MyPolygon::paint(QPainter* painter, QPaintEvent* event, double size_scale)
{
    painter->save();
    painter->translate(MyDrawItem::center_);
    painter->rotate(-theta_);
    painter->setPen(QPen(MyDrawItem::color_, MyDrawItem::size_ / size_scale, Qt::SolidLine, Qt::RoundCap));
    painter->drawPath(polygon_);
    painter->setBrush(QBrush(MyDrawItem::color2_, Qt::SolidPattern));
    painter->drawPath(polygon_);

    painter->restore();
}

bool MyPolygon::contains(const QPointF& point) const
{
    // Rotate point (reverse as in painter)
    QTransform tf;
    tf.rotate(theta_);
    tf.translate(-MyDrawItem::center_.x(), -MyDrawItem::center_.y());
    QPointF rotated = point * tf;
    return polygon_.contains(rotated);
}

void MyPolygon::update(const QPolygonF& polygon)
{
    polygon_ = QPainterPath();
    polygon_.addPolygon(polygon);
}

}  // namespace my_space
