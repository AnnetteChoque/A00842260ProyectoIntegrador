
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

    p.Calificar(6);
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

TEST(VideoTest, CalificacionesInvalidas) {
    Pelicula p("mov004", "Invalid Ratings", 120, "Test");

    p.Calificar(-1);
    p.Calificar(0);
    p.Calificar(6);
    EXPECT_DOUBLE_EQ(p.ObtenerCalPromedio(), 0.0);

    p.Calificar(3);
    EXPECT_DOUBLE_EQ(p.ObtenerCalPromedio(), 3.0);
}

TEST(VideoTest, MultiplesCalificaciones) {
    Pelicula p("mov005", "Multiple Ratings", 90, "Test");

    for(int i = 0; i < 100; i++) {
        p.Calificar(3);
    }

    EXPECT_DOUBLE_EQ(p.ObtenerCalPromedio(), 3.0);
}

TEST(DestructorTest, DestruccionPelicula) {
    Video* v = new Pelicula("mov006", "Temp Movie", 100, "Test");
    ASSERT_NO_THROW(delete v);
}

TEST(DurationTest, DuracionInvalida) {
    Pelicula p("mov007", "Short Film", 0, "Short");
    EXPECT_DOUBLE_EQ(p.GetDuracion(), 0.0);

    Pelicula p2("mov008", "Negative Film", -10, "Error");
    EXPECT_DOUBLE_EQ(p2.GetDuracion(), -10.0);
}

TEST(VideoTest, PromedioCalificacionPrecision) {
    Pelicula p("mov010", "Precision Test", 100, "Math");
    p.Calificar(3);
    p.Calificar(4);
    p.Calificar(5);

    EXPECT_NEAR(p.ObtenerCalPromedio(), 4.0, 0.0001);
}

TEST(VideoTest, CalificacionConDecimales) {

    Pelicula p("mov011", "Decimal Test", 90, "Math");

    p.Calificar(static_cast<int>(4.8));
    EXPECT_DOUBLE_EQ(p.ObtenerCalPromedio(), 4.0);
}