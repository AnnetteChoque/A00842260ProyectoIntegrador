//
// Created by Annette on 14/06/2025.
//

#include <gtest/gtest.h>
#include "clases.h"
#include <vector>

TEST(AppTest, FiltrarPeliculasPorCalificacion) {
    vector<Video*> videos;

    Pelicula* p1 = new Pelicula("P001", "Inception", 148, "accion");
    p1->calificar(5);
    p1->calificar(5);

    Pelicula* p2 = new Pelicula("P002", "El Padrino", 175, "drama");
    p2->calificar(4);
    p2->calificar(3);

    videos.push_back(p1);
    videos.push_back(p2);

    testing::internal::CaptureStdout();
    for (auto vid : videos) {
        Pelicula* p = dynamic_cast<Pelicula*>(vid);
        if (p && p->obtenerCalPromedio() >= 4.5)
            p->mostrarInfo();
    }
    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Inception"), string::npos);
    EXPECT_EQ(output.find("El Padrino"), string::npos);

    delete p1;
    delete p2;
}