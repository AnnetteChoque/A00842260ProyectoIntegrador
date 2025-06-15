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

TEST(VideoTest, ConstructorVideo) {

    string id = "P018";
    string titulo = "Ejemplo";
    double duracion = 120.0;
    string genero = "accion";

    Video* video = new Pelicula(id, titulo, duracion, genero);

    EXPECT_EQ(video->GetTitulo(), titulo);
    EXPECT_DOUBLE_EQ(video->ObtenerDuracion(), duracion);
    EXPECT_EQ(video->GetGenero(), genero);

    delete video;
}

TEST(VideoTest, CalificarValido) {
    Video* video = new Pelicula("V001", "Fast and Furious", 150.0, "accion");

    // Calificación válida
    video->Calificar(4);
    EXPECT_EQ(video->ObtenerCalPromedio(), 4.0);

    // Calificación válida adicional
    video->Calificar(5);
    EXPECT_EQ(video->ObtenerCalPromedio(), 4.5);

    delete video;
}

TEST(VideoTest, CalificarInvalido) {
    Video* video = new Pelicula("V003", "Sonic", 120.0, "accion");

    // Calificación fuera de rango
    video->Calificar(6); // Debería ignorarse
    EXPECT_EQ(video->ObtenerCalPromedio(), 0.0);

    // Otra calificación fuera de rango
    video->Calificar(0); // Debería ignorarse
    EXPECT_EQ(video->ObtenerCalPromedio(), 0.0);

    delete video;
}

TEST(VideoTest, GetGenero_GetTitulo) {

    string id = "V009";
    string titulo = "Zootopia";
    double duracion = 120.0;
    string genero = "accion";

    // Crear una instancia de Video
    Video* video = new Pelicula(id, titulo, duracion, genero);

    // Verificar GetGenero
    EXPECT_EQ(video->GetGenero(), genero);

    // Verificar GetTitulo
    EXPECT_EQ(video->GetTitulo(), titulo);

    delete video;
}