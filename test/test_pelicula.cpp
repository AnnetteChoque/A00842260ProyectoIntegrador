//
// Created by Annette on 14/06/2025.
//

#include <gtest/gtest.h>
#include "clases.h"

TEST(PeliculaTest, CalculoPromedio)
{
    Pelicula p("P001", "Inception", 148, "accion");
    p.calificar(4);
    p.calificar(5);
    EXPECT_DOUBLE_EQ(p.obtenerCalPromedio(), 4.5);
}

TEST(PeliculaTest, CalificacionInvalida) {
    Pelicula p("P002", "Matrix", 120, "accion");
    p.calificar(0);
    p.calificar(6);
    EXPECT_DOUBLE_EQ(p.obtenerCalPromedio(), 0.0);
}

TEST(PeliculaTest, MostrarInformacion) {
    Pelicula p("P004", "Avatar", 180, "accion");
    p.calificar(5);
    EXPECT_NO_THROW(p.mostrarInfo());
}