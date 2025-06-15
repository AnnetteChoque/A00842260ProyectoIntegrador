//
// Created by Annette on 14/06/2025.
//

#include <gtest/gtest.h>
#include "clases.h"

TEST(VideoTest, CalificacionesValidas) {
    Pelicula p("P001", "Inception", 148, "accion");
    p.calificar(3);
    p.agregarCalificacion(4);
    EXPECT_EQ(p.calificacionPromedio(), 3.5);
}

TEST(VideoTest, CalificacionesInvalidas) {
    Pelicula p("P002", "Matrix", 120, "ciencia ficcion");
    p.calificar(0);
    p.agregarCalificacion(6);
    EXPECT_EQ(p.obtenerCalPromedio(), 0.0);
}