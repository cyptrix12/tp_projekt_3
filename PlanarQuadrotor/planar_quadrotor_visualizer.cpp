#include "planar_quadrotor_visualizer.h"

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor *quadrotor_ptr): quadrotor_ptr(quadrotor_ptr) {}

/**
 * TODO: Improve visualizetion
 * 1. XXTransform coordinates from quadrotor frame to image frame so the circle is in the middle of the screen
 * 2. XXUse more shapes to represent quadrotor (e.x. try replicate http://underactuated.mit.edu/acrobot.html#section3 or do something prettier)
 * 3. Animate proppelers (extra points)
 */
void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer> &gRenderer) {
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    float q_x, q_y, q_theta, q_x_1, q_y_1;
    int screen_width, screen_heigh;
    SDL_GetRendererOutputSize(gRenderer.get(), &screen_width, &screen_heigh);

    /* x, y, theta coordinates */
    q_x = state[0] + screen_width/2;
    q_y = state[1] + screen_heigh/2;
    q_theta = state[2];

    int lengh = 100;
    int height = 20;
    int propeler_lengh = 5;
    int propeler_height = 20;
    int propeler_distance = 8;

    int elipse_x = 18;
    int elipse_y = 8;
    int small_elipse_x = 10;
    int small_elipse_y = 5;

    float delta_x = propeler_distance * std::cos(q_theta);
    float delta_y = propeler_distance * std::sin(q_theta);
    float delta_x_1 = propeler_height * std::sin(q_theta);
    float delta_y_1 = propeler_height * std::cos(q_theta);

    float quadrator_left_x = q_x - std::cos(q_theta)*lengh/2;
    float quadrator_left_y = q_y + std::sin(q_theta)*lengh/2;
    float quadrator_right_x = q_x + std::cos(q_theta)*lengh/2;
    float quadrator_right_y = q_y - std::sin(q_theta)*lengh/2;

    //s_p = sticking point
    float propeler_left_x_s_p = quadrator_left_x + delta_x;
    float propeler_left_y_s_p = quadrator_left_y - delta_y - height/2;
    float propeler_right_x_s_p = quadrator_right_x - delta_x;
    float propeler_right_y_s_p = quadrator_right_y + delta_y - height/2;

    //s_p_1 top point of propeler leg
    float propeler_left_x_s_p_1 = propeler_left_x_s_p - delta_x_1;
    float propeler_left_y_s_p_1 = propeler_left_y_s_p - delta_y_1;
    float propeler_right_x_s_p_1 = propeler_right_x_s_p - delta_x_1;
    float propeler_right_y_s_p_1 = propeler_right_y_s_p - delta_y_1;

    static int tick_bufor = 0;

    float propeler_render_left_x_0 = propeler_left_x_s_p_1-elipse_x;
    float propeler_render_left_x_1 = propeler_left_x_s_p_1+small_elipse_x;
    float propeler_render_right_x_0 = propeler_right_x_s_p_1-elipse_x;
    float propeler_render_right_x_1 = propeler_right_x_s_p_1+small_elipse_x;

    int elipse_render_x_left = elipse_x;
    int elipse_render_x_right = small_elipse_x;
    int elipse_render_y_left = elipse_y;
    int elipse_render_y_right = small_elipse_y;
    
    if (SDL_GetTicks() - tick_bufor > 100)
    {
        this->animation_change=!(this->animation_change);
        tick_bufor = SDL_GetTicks();
    }
    if(this->animation_change)
    {
        propeler_render_left_x_0 = propeler_render_left_x_0 + elipse_x - small_elipse_x;
        propeler_render_left_x_1 = propeler_render_left_x_1 - small_elipse_x + elipse_x;
        propeler_render_right_x_0 = propeler_render_right_x_0 + elipse_x - small_elipse_x;
        propeler_render_right_x_1 = propeler_render_right_x_1 - small_elipse_x + elipse_x;

        elipse_render_x_left = small_elipse_x;
        elipse_render_x_right = elipse_x;
        elipse_render_y_left = small_elipse_y;
        elipse_render_y_right = elipse_y;
    }

    thickLineColor(gRenderer.get(), quadrator_left_x, quadrator_left_y, quadrator_right_x, quadrator_right_y, height, 0xFF979797);
    thickLineColor(gRenderer.get(), propeler_left_x_s_p, propeler_left_y_s_p, propeler_left_x_s_p_1, propeler_left_y_s_p_1, propeler_lengh, 0xFF045000);
    thickLineColor(gRenderer.get(), propeler_right_x_s_p, propeler_right_y_s_p, propeler_right_x_s_p_1, propeler_right_y_s_p_1, propeler_lengh, 0xFF045000);
    filledEllipseColor(gRenderer.get(), propeler_render_left_x_0, propeler_left_y_s_p_1, elipse_render_x_left, elipse_render_y_left, 0xFF979797);
    filledEllipseColor(gRenderer.get(), propeler_render_left_x_1, propeler_left_y_s_p_1, elipse_render_x_right, elipse_render_y_right, 0xFF979797);
    filledEllipseColor(gRenderer.get(), propeler_render_right_x_0, propeler_right_y_s_p_1, elipse_render_x_left, elipse_render_y_left, 0xFF979797);
    filledEllipseColor(gRenderer.get(), propeler_render_right_x_1, propeler_right_y_s_p_1, elipse_render_x_right, elipse_render_y_right, 0xFF979797);
} 