#include <gtest/gtest.h>
#include "clases.h"

TEST(SerieTest, ConstructorYGetters) {
    Serie s("ser001", "Breaking Bad", 45, "Drama");

    EXPECT_EQ(s.GetId(), "ser001");
    EXPECT_EQ(s.GetTitulo(), "Breaking Bad");
    EXPECT_DOUBLE_EQ(s.GetDuracion(), 45);
    EXPECT_EQ(s.GetGenero(), "Drama");
    EXPECT_DOUBLE_EQ(s.ObtenerCalPromedio(), 0);
}

TEST(SerieTest, AgregarEpisodios) {
    Serie s("ser002", "Stranger Things", 50, "Sci-Fi");
    Episodio e1("Chapter One", 1, 4.5);
    Episodio e2("Chapter Two", 1, 4.8);

    s.AgregarEpisodio(e1);
    s.AgregarEpisodio(e2);

    const vector<Episodio>& episodios = s.GetEpisodios();
    EXPECT_EQ(episodios.size(), 2);
    EXPECT_EQ(episodios[0].GetTitulo(), "Chapter One");
    EXPECT_EQ(episodios[1].GetTitulo(), "Chapter Two");
}

TEST(SerieTest, MostrarInformacion) {
    Serie s("ser003", "The Crown", 60, "Drama");
    testing::internal::CaptureStdout();
    s.MostrarInfo();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Serie: The Crown"), string::npos);
    EXPECT_NE(output.find("Genero: Drama"), string::npos);
    EXPECT_NE(output.find("Calificacion: 0"), string::npos);
}

TEST(SerieTest, MostrarEpisodiosCalificados) {
    Serie s("ser004", "Game of Thrones", 55, "Fantasy");
    s.AgregarEpisodio(Episodio("Winter Is Coming", 1, 4.5));
    s.AgregarEpisodio(Episodio("The Kingsroad", 1, 4.2));
    s.AgregarEpisodio(Episodio("The Rains of Castamere", 3, 5.0));

    testing::internal::CaptureStdout();
    s.MostrarEpsCalificados(4.5);
    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Winter Is Coming"), string::npos);
    EXPECT_NE(output.find("The Rains of Castamere"), string::npos);
    EXPECT_EQ(output.find("The Kingsroad"), string::npos); // No debería aparecer
}

TEST(SerieTest, CalificacionPromedio) {
    Serie s("ser005", "The Mandalorian", 40, "Sci-Fi");
    s.AgregarEpisodio(Episodio("Chapter 1", 1, 4.5));
    s.AgregarEpisodio(Episodio("Chapter 2", 1, 4.8));
    s.AgregarEpisodio(Episodio("Chapter 3", 1, 5.0));

    // La serie calcula el promedio de sus propias calificaciones, no de los episodios
    s.Calificar(4);
    s.Calificar(5);

    EXPECT_DOUBLE_EQ(s.ObtenerCalPromedio(), 4.5);
}