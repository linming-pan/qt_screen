/**
 * @file my_screen.hpp
 * @author Linming Pan
 * @date 10.8.2020
 * @brief Screen widget that can be moved and zoomed
 *
 */

#ifndef MY_SCREEN_HPP
#define MY_SCREEN_HPP

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QOpenGLWidget>
#include <QDebug>
#include <iostream>

#include <my_space/my_draw_item.hpp>
#include <memory>

class MyScreen : public QWidget
{
    using ItemPtr = std::shared_ptr<my_space::MyDrawItem>;
    // using ItemPtr = my_space::MyDrawItem*;
    Q_OBJECT
private:
    QLayout* parent_layout_ = nullptr;
    double scale_size_ = 1;
    QPointF offset_;
    QPointF center_;
    QPointF press_point_;

    std::vector<ItemPtr> draw_items_;

public slots:
    void animate();

    void setCenter(const QPointF& center);

signals:
    void mousePressed(const QPointF&);

    void mouseMoved(const QPointF&);

    void mouseReleased(const QPointF&);

    void clickedItems(const std::vector<ItemPtr>& items);

public:
    MyScreen(QWidget* parent);

    ~MyScreen()
    {
        // for (auto& item : draw_items_)
        // {
        //     delete draw_p_items_;
        // }
    }

    void setParentLayout(QLayout* layout)
    {
        parent_layout_ = layout;
    }

    void addDrawItem(const ItemPtr& item)
    {
        draw_items_.push_back(item);
        qDebug() << "item count:" << draw_items_.size();
    }


protected:
    void mousePressEvent(QMouseEvent* event);

    void mouseReleaseEvent(QMouseEvent* event);

    void mouseMoveEvent(QMouseEvent* event);

    void wheelEvent(QWheelEvent* event);

    void paintEvent(QPaintEvent* event) override;

    void showEvent(QShowEvent* event);

    void resizeEvent(QResizeEvent* event);

    QPointF getOffset() const;

    QPointF getMousePoint(const QPoint& event_point) const;
};

#endif  // MY_SCREEN_HPP
