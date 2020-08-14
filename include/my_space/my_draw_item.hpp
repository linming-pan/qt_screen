/**
 * @file my_draw_item.hpp
 * @author Linming Pan
 * @date 10.8.2020
 * @brief Base DrawItem class for drawable items
 *
 */

#ifndef MY_DRAW_ITEM_HPP
#define MY_DRAW_ITEM_HPP

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QOpenGLWidget>
#include <QDebug>
#include <iostream>
#include <QPainterPath>

namespace my_space
{
class MyDrawItem
{
protected:
    QColor color_;    // Main color
    QColor color2_;   // Secondary color
    QPointF center_;  // Center point of the item
    qreal size_ = 1;  // Size of thickness of the item

    QPen paintpen_;
    QString name_;
    QString type_code_;

public:
    MyDrawItem(const QString& name, const QString& type_code)
        : name_(name)
        , type_code_(type_code)
    {
    }

    virtual ~MyDrawItem()
    {
    }

    virtual void paint(QPainter* painter, QPaintEvent* event, double size_scale = 1) = 0;

    // If drawed item cointains point
    virtual bool contains(const QPointF& point) const = 0;
    // { QPainterPath::contains(QPointF); }

    // ------------------------
    //   Get and Set functions
    // ------------------------

    inline virtual QPointF getCenter() const
    {
        return center_;
    }

    inline virtual QString getName() const
    {
        return name_;
    }

    inline qreal getSize() const
    {
        return size_;
    }

    inline QColor getColor() const
    {
        return color_;
    }

    inline QColor getColor2() const
    {
        return color2_;
    }

    inline QString getTypeCode() const
    {
        return type_code_;
    }

    inline virtual void setCenter(const QPointF& center)
    {
        center_ = center;
    }

    inline virtual void setName(const QString& name)
    {
        name_ = name;
    }

    inline void setSize(qreal size)
    {
        size_ = size;
    }

    inline void setColor(const QColor& color)
    {
        color_ = color;
    }

    inline void setColor2(const QColor& color)
    {
        color2_ = color;
    }
};

}  // namespace my_space

#endif  // MY_DRAW_ITEM_HPP
