/**
 * @file my_screen.cpp
 * @author Linming Pan
 * @date 10.8.2020
 * @brief
 *
 */

#include "my_space/my_screen.hpp"

#include <QTimer>

MyScreen::MyScreen(QWidget* parent)
    : QWidget(parent)
{
    setAutoFillBackground(false);

    center_ = QPointF(0, 0);
}

void MyScreen::animate()
{
    update();
}

void MyScreen::setCenter(const QPointF& center)
{
    center_ = QPointF(-center.x(), center.y());
}

void MyScreen::mousePressEvent(QMouseEvent* event)
{
    press_point_ = event->pos();

    QPointF coordinate = getMousePoint(event->pos());
    emit mousePressed(coordinate);
}

void MyScreen::mouseReleaseEvent(QMouseEvent* event)
{
    const QPointF click_point = getMousePoint(event->pos());

    std::vector<ItemPtr> items;
    for (const auto& item : draw_items_)
    {
        if (item->contains(click_point))
        {
            items.push_back(item);
        }
    }
    emit mouseReleased(click_point);
    emit clickedItems(items);
}

void MyScreen::mouseMoveEvent(QMouseEvent* event)
{
    const QPoint point = event->pos();
    QPointF change = (point - press_point_) / scale_size_;
    press_point_ = point;
    center_ += change;

    emit mouseMoved(point);
}

void MyScreen::wheelEvent(QWheelEvent* event)
{
    center_ = getMousePoint(event->pos());
    if (event->delta() > 1)
    {
        scale_size_ *= 1.3;
    }
    else if (event->delta() < -1)
    {
        scale_size_ /= 1.3;
    }
    center_ = getMousePoint(event->pos());
}

void MyScreen::paintEvent(QPaintEvent* event)
{
    QPointF offset = getOffset();

    QPainter painter;
    painter.begin(this);
    painter.scale(scale_size_, scale_size_);
    painter.rotate(0);
    painter.translate(offset);
    painter.setRenderHint(QPainter::Antialiasing);

    for (auto item : draw_items_)
    {
        item->paint(&painter, event, scale_size_);
    }

    painter.end();
}

void MyScreen::showEvent(QShowEvent* event)
{
    center_ = QPoint(0, 0);
}

void MyScreen::resizeEvent(QResizeEvent* event)
{
    // std::cout << "event: " << event << std::endl;
    // std::cout << "parent_layout_: " << parent_layout_ << std::endl;
}

QPointF MyScreen::getOffset() const
{
    return center_ + QPointF(width(), height()) / 2 / scale_size_;
}

QPointF MyScreen::getMousePoint(const QPoint& event_point) const
{
    return (event_point / scale_size_) - getOffset();
}
