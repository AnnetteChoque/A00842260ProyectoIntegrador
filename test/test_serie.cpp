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
    EXPECT_EQ(output.find("The Kingsroad"), string::npos);
}

TEST(SerieTest, CalificacionPromedio) {
    Serie s("ser005", "The Mandalorian", 40, "Sci-Fi");
    s.AgregarEpisodio(Episodio("Chapter 1", 1, 4.5));
    s.AgregarEpisodio(Episodio("Chapter 2", 1, 4.8));
    s.AgregarEpisodio(Episodio("Chapter 3", 1, 5.0));

    s.Calificar(4);
    s.Calificar(5);

    EXPECT_DOUBLE_EQ(s.ObtenerCalPromedio(), 4.5);
}

TEST(SerieTest, SerieSinEpisodios) {
    Serie s("ser006", "Empty Series", 30, "Test");

    testing::internal::CaptureStdout();
    s.MostrarEpsCalificados(1.0);
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.empty());
}

TEST(SerieTest, CalificacionEpisodiosNoAfectaSerie) {
    Serie s("ser007", "Independent Ratings", 45, "Test");
    Episodio e("Test Episode", 1, 5.0);
    s.AgregarEpisodio(e);

    EXPECT_DOUBLE_EQ(s.ObtenerCalPromedio(), 0.0);

    s.Calificar(2.0);
    EXPECT_DOUBLE_EQ(s.ObtenerCalPromedio(), 2.0);
}

TEST(SerieTest, TodosEpisodiosCalificados) {
    Serie s("ser008", "All Rated", 40, "Test");
    for(int i = 1; i <= 5; i++) {
        s.AgregarEpisodio(Episodio("Ep " + to_string(i), 1, i));
    }

    testing::internal::CaptureStdout();
    s.MostrarEpsCalificados(0.5);
    string output = testing::internal::GetCapturedStdout();

    for(int i = 1; i <= 5; i++) {
        EXPECT_NE(output.find("Ep " + to_string(i)), string::npos);
    }
}

TEST(SerieTest, NingunEpisodioCalificado) {
    Serie s("ser009", "None Rated", 40, "Test");
    for(int i = 1; i <= 3; i++) {
        s.AgregarEpisodio(Episodio("Ep " + to_string(i), 1, 0.0));
    }

    testing::internal::CaptureStdout();
    s.MostrarEpsCalificados(1.0);
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.empty());
}

TEST(DestructorTest, DestruccionSerieConEpisodios) {
    Serie* s = new Serie("ser010", "Temp Serie", 40, "Test");
    s->AgregarEpisodio(Episodio("Temp Ep", 1, 3.0));
    ASSERT_NO_THROW(delete s);
}

TEST(TemporadaTest, TemporadaInvalida) {
    Episodio e("Invalid Season", -1, 3.0);
    EXPECT_EQ(e.GetTemporada(), -1);
}