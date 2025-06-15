
#include <gtest/gtest.h>
#include "clases.h"

TEST(PeliculaTest, ConstructorYGetters) {
    Pelicula p("mov001", "Inception", 148, "Sci-Fi");

    EXPECT_EQ(p.GetId(), "mov001");
    EXPECT_EQ(p.GetTitulo(), "Inception");
    EXPECT_DOUBLE_EQ(p.GetDuracion(), 148);
    EXPECT_EQ(p.GetGenero(), "Sci-Fi");
    EXPECT_DOUBLE_EQ(p.ObtenerCalPromedio(), 0);
}

TEST(PeliculaTest, Calificacion) {
    Pelicula p("mov002", "The Matrix", 136, "Sci-Fi");

    p.Calificar(5);
    EXPECT_DOUBLE_EQ(p.ObtenerCalPromedio(), 5);

    p.Calificar(4);
    EXPECT_DOUBLE_EQ(p.ObtenerCalPromedio(), 4.5);

    p.Calificar(6); // Calificación inválida (no debería afectar)
    EXPECT_DOUBLE_EQ(p.ObtenerCalPromedio(), 4.5);
}

TEST(PeliculaTest, MostrarInformacion) {
    Pelicula p("mov003", "Interstellar", 169, "Sci-Fi");
    p.Calificar(5);
    p.Calificar(4);

    testing::internal::CaptureStdout();
    p.MostrarInfo();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Pelicula: Interstellar"), string::npos);
    EXPECT_NE(output.find("Duracion: 169"), string::npos);
    EXPECT_NE(output.find("Genero: Sci-Fi"), string::npos);
    EXPECT_NE(output.find("Calificacion: 4.5"), string::npos);
}