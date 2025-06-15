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
