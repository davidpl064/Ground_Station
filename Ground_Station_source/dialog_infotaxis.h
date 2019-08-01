#ifndef DIALOG_INFOTAXIS_H
#define DIALOG_INFOTAXIS_H

#include <QDialog>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QHeightMapSurfaceDataProxy>
#include <QtDataVisualization/QSurface3DSeries>

using namespace QtDataVisualization;

#include "infotaxis.h"

// Include .ui file of the dialog:
#include "ui_dialog_infotaxis.h"

// Libraries for matrix operations:
#include <Eigen/Dense>

using namespace Eigen;

namespace Ui
{
    class Dialog_Infotaxis;
}

class Dialog_Infotaxis : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog_Infotaxis(QWidget *parent = nullptr);
    ~Dialog_Infotaxis();
    void setup(Lattice&, Model&);
    void update();

protected:

private:
    QHBoxLayout *horizontal_layout;
    QVBoxLayout *vertical_layout;

    QSurfaceDataProxy *proxy_surface = new QSurfaceDataProxy();
    QSurface3DSeries *serie_surface = new QSurface3DSeries(proxy_surface);

    Q3DSurface *surface_density_function = new Q3DSurface();
    Ui::Dialog_Infotaxis *ui;
};

#endif // DIALOG_INFOTAXIS_H
