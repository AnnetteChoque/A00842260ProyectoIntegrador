//
// Created by Annette on 15/06/2025.
//
#include <gtest/gtest.h>
#include "clases.h"

TEST(EpisodioTest, MostrarInformacionEpisodio) {
    Episodio e("Finale", 5, 4.8);
    testing::internal::CaptureStdout();
    e.MostrarInfo();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Episodio: Finale"), string::npos);
}

TEST(EpisodioTest, ObtenerDatosEpisodio) {
    Episodio e("Pilot", 1, 3.5);
    EXPECT_EQ(e.GetTitulo(), "Pilot");
    EXPECT_EQ(e.GetTemporada(), 1);
    EXPECT_DOUBLE_EQ(e.GetCalificacion(), 3.5);
}

TEST(CoverageTest, MostrarEpsCalificados_ConCoincidencias) {
    Serie s("S300", "Series X", 40.0, "Action");
    s.AgregarEpisodio(Episodio("E1", 1, 5.0));
    s.AgregarEpisodio(Episodio("E2", 1, 3.0));

    testing::internal::CaptureStdout();
    s.MostrarEpsCalificados(4.0); // Solo "E1" debe aparecer
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Episodio: E1"), string::npos);
    EXPECT_EQ(output.find("Episodio: E2"), string::npos);
}

TEST(CoverageTest, MostrarEpsCalificados_SinCoincidencias) {
    Serie s("S301", "Series Y", 40.0, "Drama");
    s.AgregarEpisodio(Episodio("E1", 1, 2.5));
    s.AgregarEpisodio(Episodio("E2", 1, 3.0));

    testing::internal::CaptureStdout();
    s.MostrarEpsCalificados(4.0); // No debe imprimirse nada
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty());
}

TEST(CoverageTest, MostrarEpsCalificados_EjecutaMostrarInfo) {
    Serie s("S2025", "SerieEpisodio", 45, "Misterio");
    Episodio ep1("Episodio Bueno", 1, 5.0); 
    s.AgregarEpisodio(ep1);

    testing::internal::CaptureStdout();
    s.MostrarEpsCalificados(4.5);
    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Episodio: Episodio Bueno"), string::npos);
    EXPECT_NE(output.find("Temporada: 1"), string::npos);
    EXPECT_NE(output.find("Calificacion: 5"), string::npos);
}
