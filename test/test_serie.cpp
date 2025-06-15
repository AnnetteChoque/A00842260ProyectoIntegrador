#include <gtest/gtest.h>
#include "clases.h"

TEST(SerieTest, CrearSerieYMostrarInfo) {
    Serie s("S1", "Breaking Bad", 50, "Drama");
    testing::internal::CaptureStdout();
    s.MostrarInfo();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Serie: Breaking Bad"), string::npos);
}

TEST(SerieTest, AgregarEpisodiosYFiltrarPorCalificacion) {
    Serie s("S2", "Dark", 60, "Thriller");
    s.AgregarEpisodio(Episodio("E1", 1, 4.5));
    s.AgregarEpisodio(Episodio("E2", 1, 3.0));
    testing::internal::CaptureStdout();
    s.MostrarEpsCalificados(4.0);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Episodio: E1"), string::npos);
    EXPECT_EQ(output.find("Episodio: E2"), string::npos); // no se imprime
}

TEST(SerieTest, ObtenerEpisodiosListaCompleta) {
    Serie s("S3", "Stranger Things", 55, "Adventure");
    s.AgregarEpisodio(Episodio("E1", 1, 5.0));
    s.AgregarEpisodio(Episodio("E2", 2, 4.0));
    auto eps = s.GetEpisodios();
    EXPECT_EQ(eps.size(), 2);
    EXPECT_EQ(eps[0].GetTitulo(), "E1");
}

TEST(VideoConstructorTest, VerificaConstructorDeVideoDesdeSerie) {
    Serie s("S100", "The 100", 45.0, "Sci-Fi");
    EXPECT_EQ(s.GetId(), "S100");
    EXPECT_EQ(s.GetTitulo(), "The 100");
    EXPECT_DOUBLE_EQ(s.GetDuracion(), 45.0);
    EXPECT_EQ(s.GetGenero(), "Sci-Fi");
}

TEST(CoverageTest, ConstructorSerieVideoBase) {
    Serie s("S200", "Test Show", 45.0, "Thriller");
    EXPECT_EQ(s.GetId(), "S200");
    EXPECT_EQ(s.GetTitulo(), "Test Show");
    EXPECT_EQ(s.GetGenero(), "Thriller");
    EXPECT_DOUBLE_EQ(s.GetDuracion(), 45.0);
}

TEST(CoverageTest, ConstructorSerie_Completo) {
    Serie s("S999", "SerieCover", 60.5, "Documental");

    EXPECT_EQ(s.GetId(), "S999");
    EXPECT_EQ(s.GetTitulo(), "SerieCover");
    EXPECT_EQ(s.GetGenero(), "Documental");
    EXPECT_DOUBLE_EQ(s.GetDuracion(), 60.5);

    s.Calificar(4);
    testing::internal::CaptureStdout();
    s.MostrarInfo();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Serie: SerieCover"), string::npos);
    EXPECT_NE(output.find("Genero: Documental"), string::npos);
    EXPECT_NE(output.find("Calificacion: 4"), string::npos);
}