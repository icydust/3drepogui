/**
 *  Copyright (C) 2015 3D Repo Ltd
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef REPO_COMBO_BOX_EDITOR_H
#define REPO_COMBO_BOX_EDITOR_H


//------------------------------------------------------------------------------
// Qt
#include <QWidget>
#include <QByteArray>
#include <QComboBox>
#include <QList>
#include <QString>
#include <QItemEditorCreatorBase>

namespace repo {
namespace gui {


// See http://doc-snapshot.qt-project.org/qt5-5.4/qitemeditorcreatorbase.html
class RepoComboBoxEditor : public QComboBox, public QItemEditorCreatorBase
{
    Q_OBJECT

    Q_PROPERTY(QColor color READ color WRITE setColor USER true)

public:
    explicit RepoComboBoxEditor(const std::list<std::string> &list, QWidget *parent = 0);

    ~RepoComboBoxEditor();

public:
    QColor color() const;
    void setColor(QColor c);

    //! Returns an editor widget with the given parent.
    QWidget * createWidget(QWidget * parent) const;

    //! Returns empty QByteArray.
    QByteArray valuePropertyName() const;

private:

    //! List of items to be displayed.
    std::list<std::string> list;
};

} // end namespace gui
} // end namespace repo

#endif // REPO_COMBO_BOX_EDITOR_H
