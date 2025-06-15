
#include <gtest/gtest.h>
#include "clases.h"

TEST(PeliculaTest, CrearPeliculaYMostrarInfo) {
    Pelicula p("P1", "Interstellar", 169.0, "Sci-Fi");
    testing::internal::CaptureStdout();
    p.MostrarInfo();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Pelicula: Interstellar"), string::npos);
}

TEST(PeliculaTest, CalificarPeliculaPromedio) {
    Pelicula p("P2", "Inception", 148.0, "Sci-Fi");
    p.Calificar(4);
    p.Calificar(5);
    EXPECT_DOUBLE_EQ(p.ObtenerCalPromedio(), 4.5);
}

TEST(PeliculaTest, CalificacionInvalidaNoSeAgrega) {
    Pelicula p("P3", "Avatar", 160.0, "Fantasy");
    p.Calificar(6); // inválida
    p.Calificar(0); // inválida
    EXPECT_DOUBLE_EQ(p.ObtenerCalPromedio(), 0.0);
}

TEST(VideoTest, MétodosGettersGenerales) {
    Pelicula p("VID123", "Matrix", 120, "Action");
    EXPECT_EQ(p.GetId(), "VID123");
    EXPECT_EQ(p.GetTitulo(), "Matrix");
    EXPECT_EQ(p.GetGenero(), "Action");
    EXPECT_DOUBLE_EQ(p.GetDuracion(), 120);
}

TEST(VideoConstructorTest, VerificaConstructorDeVideoDesdePelicula) {
    Pelicula p("P100", "Duna", 155.0, "Sci-Fi");
    EXPECT_EQ(p.GetId(), "P100");
    EXPECT_EQ(p.GetTitulo(), "Duna");
    EXPECT_DOUBLE_EQ(p.GetDuracion(), 155.0);
    EXPECT_EQ(p.GetGenero(), "Sci-Fi");
}

TEST(CoverageTest, ConstructorPeliculaVideoBase) {
    Pelicula p("P100", "Test Movie", 90.5, "Comedy");
    EXPECT_EQ(p.GetId(), "P100");
    EXPECT_EQ(p.GetTitulo(), "Test Movie");
    EXPECT_EQ(p.GetGenero(), "Comedy");
    EXPECT_DOUBLE_EQ(p.GetDuracion(), 90.5);
}

TEST(CoverageTest, ConstructorPelicula_Completo) {
    Pelicula p("P999", "PeliCover", 120.5, "Terror");

    EXPECT_EQ(p.GetId(), "P999");
    EXPECT_EQ(p.GetTitulo(), "PeliCover");
    EXPECT_EQ(p.GetGenero(), "Terror");
    EXPECT_DOUBLE_EQ(p.GetDuracion(), 120.5);

    p.Calificar(5);
    testing::internal::CaptureStdout();
    p.MostrarInfo();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Pelicula: PeliCover"), string::npos);
    EXPECT_NE(output.find("Duracion: 120.5"), string::npos);
    EXPECT_NE(output.find("Genero: Terror"), string::npos);
    EXPECT_NE(output.find("Calificacion: 5"), string::npos);
}