#include "infotaxis.h"

Infotaxis::Infotaxis()
{

}

void Infotaxis::setup(Lattice &lattice_parameters, Model &model_parameters)
{
    // Initialize lattice variables:
    nodes_x = lattice_parameters.nodes_x;
    nodes_y = lattice_parameters.nodes_y;

    delta_x = lattice_parameters.Lx/(lattice_parameters.nodes_x - 1);
    delta_y = lattice_parameters.Ly/(lattice_parameters.nodes_y - 1);

    x_grid.setLinSpaced(lattice_parameters.nodes_x, 0, lattice_parameters.Lx);
    y_grid.setLinSpaced(lattice_parameters.nodes_y, 0, lattice_parameters.Ly);

    // Round source and searcher position to nearest nodes:
    //rs_0 = [round(config_nueva.rs_x0/delta_x) * delta_x, round(config_nueva.rs_y0/delta_y) * delta_y];
    // r_searcher.
    //rf = [round(lattice_parameters.r0_searcher[0]/delta_x) * delta_x, round(lattice_parameters.r0_searcher[1]/delta_y) * delta_y];
    // r_fuente.
    // rs_z0 = config_nueva.rs_z0;
    // rf_z0 = config_nueva.rf_z0;

    // Model parameters:
    N = lattice_parameters.nodes_x * lattice_parameters.nodes_y;
    D = model_parameters.diffusion_coeff;
    tau = model_parameters.tau;
    gamma = model_parameters.gamma;
    a = model_parameters.a_sensor;
    delta_t = model_parameters.delta_t;

    error_bessel = 1e-8;
    error_wind = 1e50;
}

void Infotaxis::search_step()
{
//    if (S_t > stop_search_criteria)
//    {
//        // Check boundary restrictions:
//        // Order is: [stay, up, down, right, left].
//        if(r_searcher(1) <= 1e-6)
//        {
//            if(r_searcher(2) <= 1e-6)
//            {
//                number_possible_movements = 3;
//                mov_possible.head(number_possible_movements) << 0, 1, 3;

//                //limite = [1, 0, -1, 1, 0];
//            }
//            else if (Ly - r_searcher(2) <= 1e-6)
//            {
//                number_possible_movements = 3;
//                mov_possible.head(number_possible_movements) << 0, 2, 3;

//                //limite = [1, 0, 0, 1, 1];
//            }
//            else
//            {
//                number_possible_movements = 4;
//                mov_possible.head(number_possible_movements) << 0, 1, 2, 3;

//                //limite = [1, 0, -1, 1, 1];
//            }
//        }
//        else if(Lx - r_searcher(1) <= 1e-6)
//        {
//            if (r_searcher(2) <= 1e-6)
//            {
//                number_possible_movements = 3;
//                mov_possible.head(number_possible_movements) << 0, 1, 4;

//                //limite = [1, -1, -1, 0, 0];
//            }
//            else if (Ly - r_searcher(2) <= 1e-6)
//            {
//                number_possible_movements = 3;
//                mov_possible.head(number_possible_movements) << 0, 2, 4;

//                //limite = [1, -1, 0, 0, 1];
//            }
//            else
//            {
//                number_possible_movements = 4;
//                mov_possible.head(number_possible_movements) << 0, 1, 2, 4;
//            }
//        }
//        else if (r_searcher(2) <= 1e-6)
//        {
//            number_possible_movements = 4;
//            mov_possible.head(number_possible_movements) << 0, 1, 3, 4;
//        }
//        else if (Ly - r_searcher(2) <= 1e-6)
//        {
//            number_possible_movements = 4;
//            mov_possible.head(number_possible_movements) << 0, 2, 3, 4;

//            //limite = [1, -1, 0, 1, 1];
//        }
//        else
//        {
//            // Inside the domain, free movement:
//            number_possible_movements = 5;
//            mov_possible.head(number_possible_movements) << 0, 1, 2, 3, 4;

//            //limite = [1, -1, -1, 1, 1];
//        }

//        lambda = sqrt(D * tau / (1 + pow(Vw, 2) * tau/ (4 * D)));

//        // Estimate mean detection rate R(r'|r0), to decide next step:
//        delta_S = VectorXd::Zero(1, number_possible_movements);
//        for (uint z = 0; z < number_possible_movements; z++)
//        {
//            switch (mov_possible(z))
//            {
//            case 1: {
//                rj = r_searcher;
//            }
//            case 2: {
//                rj = r_searcher + Vector2d(0, delta_y);
//            }
//            case 3: {
//                rj = r_searcher + Vector2d(0, -delta_y);
//            }
//            case 4: {
//                rj = r_searcher + Vector2d(delta_x, 0);
//            }
//            case 5: {
//                rj = r_searcher + Vector2d(-delta_x, 0);
//            }
//            }

//            for (uint i = 0; i < nodes_x; i++)
//            {
//                for (uint j = 0; j < nodes_y; j++)
//                {
//                    v_bessel_aux = pow((pow((rj(1) - delta_x * i), 2) + pow((rj(2) + delta_y * j), 2)), 0.5) / lambda; // It's a distance so no need to rotate to wind-related axis.
//                    // Check low values to avoid infinity singularity:
//                    if (v_bessel_aux > error_bessel)
//                    {
//                        v_bessel(j, i) = v_bessel_aux;
//                    }
//                    else
//                    {
//                        v_bessel(j, i) = error_bessel;
//                    }
//                    bessel_function(j, i) = std::cyl_bessel_k(0, v_bessel(j, i));

//                    wind_term_aux = exp(Vw * -(sin(angle_wind_direction) * (delta_x * i - rj(1)) + cos(angle_wind_direction) * (-delta_y * j - rj(2))) / (2 * D));
//                    // Check high values to avoid infinity singularity:
//                    if (wind_term_aux < error_wind)
//                    {
//                        wind_term(j, i) = wind_term_aux;
//                    }
//                    else
//                    {
//                        wind_term(j, i) = error_wind;
//                    }
//                }
//            }

//            //bessel_function = cyl_bessel_k(0, v_bessel);
//            R_rs = gamma * wind_term * bessel_function / log(lambda/a);

//            // Correction source not found at rj:
//            f_density_delta_t = f_density;
//            //f_densidad_delta_t(fila(z), columna(z)) = 0;
//            Sum_f_density_delta_t = f_density_delta_t.sum();
//            f_density_delta_t = f_density_delta_t / (Sum_f_density_delta_t * delta_x * delta_y);
//            R_mean = (delta_t * f_density_delta_t * R_rs * delta_x * delta_y).sum();

//            // Estimation of k_max:
//            double suma_ro = 0;
//            uint k = 0;
//            double error_kmax = 1;
//            while (error_kmax > delta_k)
//            {
//                suma_ro += pow(R_mean, k)/factorial(k) * exp(- R_mean);
//                error_kmax = 1 - suma_ro;
//                k = k + 1;
//            }
//            k_max = k;

//            // Sumatorio hasta k_max:
//            for (uint k = 0; k < k_max; k++)
//            {
//                f_density_delta_t = f_density * R_rs.pow(k) * ((- delta_t * R_rs).exp());

//                // Correction source not found at rj:
//                //f_density_delta_t(fila(z), columna(z)) = 0;
//                Sum_f_density_delta_t = f_density_delta_t.sum();
//                f_density_delta_t = f_density_delta_t/(Sum_f_density_delta_t * delta_x * delta_y);
//                S_delta_t = - (f_density_delta_t * (f_density_delta_t * delta_x * delta_y).log()).sum() * pow(delta_x, 2) * pow(delta_y, 2); // Already avoided singularity null terms.
//                delta_Sk = S_delta_t - S_t;
//                Sum_k_max += pow(R_mean, k)/factorial(k) * exp(- R_mean) * delta_Sk;
//            }

//            // Calculate "EXPECTED" entropy change (DeltaS) in possible next positions:
//            //        for (k = 0; k < number_possible_movements; k++)
//            //        {
//            //            m = m_posibles(k);
//            //            switch (m) {
//            //            case 1: {
//            //                rj = rs;
//            //            }
//            //            case 2: {
//            //                rj = rs + [-delta_x, 0];
//            //            }
//            //            case 3: {
//            //                rj = rs + [0, delta_y];
//            //            }
//            //            case 4: {
//            //                rj = r_s + [delta_x, 0];
//            //            }
//            //            case 5: {
//            //                rj = rs + [0, -delta_y];
//            //            }
//            //            }

//            delta_S(z) = - f_density(uint16(nodes_y - rj(2)/delta_y), uint16(rj(1)/delta_x + 1)) * delta_x * delta_y * S_t + (1 - f_density(uint16(nodes_y - rj(2)/delta_y), uint16(rj(1)/delta_x + 1))) * delta_x * delta_y * Sum_k_max;
//        }

//        // Decide next step node:
//        // Choose randomly in case of more than one equivalent point.
//        // Boundary restriction is considered.
//        max_deltaS = min(delta_S);
//        puntos_candidatos = find(delta_S == max_deltaS);

//        punto_posible = puntos_candidatos(round(rand * (length(puntos_candidatos) - 1)) + 1);
//        selected_point = mov_possible(punto_posible);

//        // Move to selected next point:
//        switch (selected_point) {
//        case 0: {}
//        case 1: {
//            r_searcher = r_searcher + Vector2d(-delta_x, 0);
//        }
//        case 2: {
//            r_searcher = r_searcher + Vector2d(0, delta_y);
//        }
//        case 3: {
//            r_searcher = r_searcher + Vector2d(delta_x, 0);
//        }
//        case 4: {
//            r_searcher = r_searcher + Vector2d(0, -delta_y);
//        }
//        }

//        // Update Probability Density function based on "EXPERIENCED" odour detections (v), in interval dt:
//        f_density = f_density * R_rs.pow(num_odour_detections) * (- delta_t * R_rs).exp();
//        Sum_f_density = f_density.sum();

//        f_density = f_density / (Sum_f_density * delta_x * delta_y);
//        S_t = - (f_density_delta_t * (f_density_delta_t * delta_x * delta_y).log()).sum() * pow(delta_x, 2) * pow(delta_y, 2);

//        // Graphical display:
//        P_t = flipud(f_density) * delta_x * delta_y;
//        P_t(P_t < 1e-10) = 1e-10; // Condicion no corte la grafica y quede 'feo'. Empeora rendimiento.
//        //Concentracion = flipud(R_real(:, :, n_R_real)) / (4 * pi * D * a);
//    }
}
