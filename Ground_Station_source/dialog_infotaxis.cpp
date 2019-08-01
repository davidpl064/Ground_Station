#include "dialog_infotaxis.h"

Dialog_Infotaxis::Dialog_Infotaxis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Infotaxis)
{
    ui->setupUi(this);

    // Setup surfaces for data display:
    QWidget *container = QWidget::createWindowContainer(surface_density_function);

    horizontal_layout = new QHBoxLayout(ui->surface_widget);
    vertical_layout = new QVBoxLayout();
    horizontal_layout->addWidget(container, 1);
    horizontal_layout->addLayout(vertical_layout);
    vertical_layout->setAlignment(Qt::AlignTop);

    // Set labels and axis formats:
    serie_surface->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
    serie_surface->setFlatShadingEnabled(true);

    surface_density_function->axisX()->setLabelFormat("%.2f");
    surface_density_function->axisZ()->setLabelFormat("%.2f");
    surface_density_function->axisX()->setLabelAutoRotation(30);
    surface_density_function->axisY()->setLabelAutoRotation(90);
    surface_density_function->axisZ()->setLabelAutoRotation(30);

    surface_density_function->axisZ()->setRange(0.0f, 1.0f);

    surface_density_function->addSeries(serie_surface);

    // Item selection mode by default:
    surface_density_function->setSelectionMode(QAbstract3DGraph::SelectionItem);
}

Dialog_Infotaxis::~Dialog_Infotaxis()
{
    //dtor
}

void Dialog_Infotaxis::setup(Lattice &lattice_parameters, Model &model_parameters)
{
    // Set X/Y axis ranges in accordance to lattice domain:
    surface_density_function->axisX()->setRange(0.0f, lattice_parameters.Lx);
    surface_density_function->axisY()->setRange(0.0f, lattice_parameters.Lx);

    surface_density_function->setOrthoProjection(true);

    this->show();

    // Condicion Vw y alpha variables:
    //    R_real = zeros(nodos_y, nodos_x, length(delta_Vw) * length(delta_alpha));
    //    for t_1 = 1 : length(delta_Vw)
    //            for t_2 = 1 : length(delta_alpha)
    //            lambda = sqrt(D * tau / (1 + Vw(t_1)^2 * tau/ (4 * D)));
    //    v_bessel = ((delta_x * (i - 1) - rf(1)).^2 + (-delta_y * (j - nodos_y) - rf(2))^2)^0.5 / lambda; // Al ser una distancia no hace falta rotar a ejes viento.
    //    v_bessel(v_bessel < 1e-12) = error_bessel; // Condicion evitar infinito.
    //    viento_term = exp(Vw(t_1) * -(sin(theta(t_2)) * (rf(1) - 1 - delta_x * (i - 1)) + cos(theta(t_2)) * (rf(2) + 1 + delta_y * (j - nodos_y))) / (2 * D));
    //    viento_term(viento_term > error_viento) = error_viento; // Condicion evitar infinito.
    //    R_real(:, :, length(delta_alpha) * (t_1 - 1) + t_2) = gamma * viento_term .* besselk(0, v_bessel) / log(lambda/a);
    //    end
    //            end

    // Grafica concentracion:
    //Concentracion = flipud(R_real(:, :, length(delta_alpha) * (n_t - 1) + n_t_2)) / (4 * pi * D * a);


//    // Initialize density function and associated entropy function:
//    density_function = 1/(N * delta_x * delta_y) * ones(lattice_parameters.nodes_y, lattice_parameters.nodes_x);
//    //S_t = log(N) * delta_x * delta_y; % Valor inicial.
//    t_min = exp(S_t - 1);

//    // Stopping criteria:
//    delta_k = 1e-8;
//    criterio_parada = 1e-4;
}


void Dialog_Infotaxis::update()
{

}
