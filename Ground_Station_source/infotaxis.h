#ifndef INFOTAXIS_H
#define INFOTAXIS_H

#include <QtGlobal>

// Libraries for matrix operations:
#include <Eigen/Dense>
#include <cmath>
//#include <boost/math/special_functions/bessel.hpp>

using namespace Eigen;

struct Lattice {
    uint nodes_x;
    uint nodes_y;
    uint Lx;
    uint Ly;
};

struct Model {
    double diffusion_coeff;
    double tau;
    double gamma;
    double a_sensor;
    double delta_t;
};

class Infotaxis
{
public:
    Infotaxis();
    void setup(Lattice&, Model&);
    void search_step();

private:
    uint nodes_x;
    uint nodes_y;
    uint Lx;
    uint Ly;

    double delta_x;
    double delta_y;
    VectorXd x_grid;
    VectorXd y_grid;

    uint N;
    double D;
    double tau;
    double gamma;
    double a;
    double lambda;
    double Vw;
    double delta_t;

    double num_odour_detections;

    double error_bessel;
    double error_wind;

    double angle_wind_direction;

    double S_t;
    double S_delta_t;
    double delta_Sk;

    double number_possible_movements;
    VectorXi mov_possible;

    double delta_k;
    double stop_search_criteria;

    Vector2d rj;
    Vector2d r_searcher;

    double k_max;
    double Sum_k_max;
    double R_mean;
    VectorXd delta_S;
    ArrayXXd R_rs;

    double v_bessel_aux;
    ArrayXXd v_bessel;
    ArrayXXd bessel_function;

    double wind_term_aux;
    ArrayXXd wind_term;

    double Sum_f_density;
    double Sum_f_density_delta_t;
    ArrayXXd f_density;
    ArrayXXd f_density_delta_t;
};

#endif // INFOTAXIS_H
