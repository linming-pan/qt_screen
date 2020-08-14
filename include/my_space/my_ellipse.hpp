/**
 * @file my_ellipse.hpp
 * @author Linming Pan
 * @date 10.8.2020
 * @brief Ellipse DrawItem
 *
 */
#ifndef MY_ELLIPSE_HPP
#define MY_ELLIPSE_HPP

#include <QPainterPath>
#include <my_space/my_draw_item.hpp>

namespace my_space
{
class MyEllipse : public MyDrawItem
{
private:
    qreal rx_ = 1;
    qreal ry_ = 1;
    qreal theta_ = 0;  // in degree

    QPainterPath ellipse_;

public:
    MyEllipse();

    MyEllipse(qreal rx, qreal ry, qreal theta);

    void updateEllipse(qreal rx, qreal ry, qreal theta);

    void paint(QPainter* painter, QPaintEvent* event, double size_scale = 1);

    bool contains(const QPointF& point) const;

private:
    void updateEllipse();
};
}  // namespace my_space

#endif  // MY_ELLIPSE_HPP
