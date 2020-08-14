/**
 * @file my_ellipse.cpp
 * @author Linming Pan
 * @date 10.8.2020
 * @brief
 *
 */

#include <my_space/my_ellipse.hpp>

namespace my_space
{
MyEllipse::MyEllipse()
    : MyDrawItem("", "elps")
{
    updateEllipse();
}

MyEllipse::MyEllipse(qreal rx, qreal ry, qreal theta)
    : MyDrawItem("", "elps")
    , rx_(rx)
    , ry_(ry)
    , theta_(theta)
{
    updateEllipse();
}

void MyEllipse::updateEllipse(qreal rx, qreal ry, qreal theta)
{
    rx_ = rx;
    ry_ = ry;
    theta_ = theta;
    updateEllipse();
}

void MyEllipse::paint(QPainter* painter, QPaintEvent* event, double size_scale)
{
    painter->save();

    painter->rotate(-theta_);
    painter->setPen(QPen(MyDrawItem::color_, MyDrawItem::size_ / size_scale, Qt::SolidLine, Qt::RoundCap));
    painter->drawPath(ellipse_);
    painter->setBrush(QBrush(MyDrawItem::color2_, Qt::SolidPattern));
    painter->drawPath(ellipse_);

    painter->restore();
}

bool MyEllipse::contains(const QPointF& point) const
{
    // Rotate point
    QTransform tf;
    tf.rotate(theta_);
    QPointF rotated = point * tf;
    return ellipse_.contains(rotated);
}

void MyEllipse::updateEllipse()
{
    ellipse_ = QPainterPath();
    QTransform tf;
    tf.rotate(theta_);
    QPointF rotated = MyDrawItem::center_ * tf;
    ellipse_.addEllipse(rotated, rx_, ry_);
}

}  // namespace my_space
