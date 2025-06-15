//
// Created by Annette on 14/06/2025.
//

#include <gtest/gtest.h>
#include "clases.h"

TEST(VideoTest, CalificacionesValidas) {
    Pelicula p("P001", "Inception", 148, "accion");
    p.Calificar(3);
    p.AgregarCalificacion(4);
    EXPECT_EQ(p.CalificacionPromedio(), 3.5);
}

TEST(VideoTest, CalificacionesInvalidas) {
    Pelicula p("P002", "Matrix", 120, "ciencia ficcion");
    p.Calificar(0);
    p.AgregarCalificacion(6);
    EXPECT_EQ(p.ObtenerCalPromedio(), 0.0);
}