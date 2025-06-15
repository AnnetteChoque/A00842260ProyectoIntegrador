//
// Created by Annette on 15/06/2025.
//
#include <gtest/gtest.h>
#include "clases.h"

TEST(EpisodioTest, ConstructorYGetters) {
    Episodio e("Piloto", 1, 4.5);

    EXPECT_EQ(e.GetTitulo(), "Piloto");
    EXPECT_EQ(e.GetTemporada(), 1);
    EXPECT_DOUBLE_EQ(e.GetCalificacion(), 4.5);
}

TEST(EpisodioTest, MostrarInformacionEpisodio) {
    Episodio e("Finale", 5, 4.8);
    testing::internal::CaptureStdout();
    e.MostrarInfo();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Episodio: Finale"), string::npos);
    EXPECT_NE(output.find("Temporada: 5"), string::npos);
    EXPECT_NE(output.find("Calificacion: 4.8"), string::npos);
}
