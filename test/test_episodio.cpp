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

TEST(EpisodioTest, CalificacionLimites) {
    Episodio e("Extremo", 1, 0.0);
    EXPECT_DOUBLE_EQ(e.GetCalificacion(), 0.0);

    Episodio e2("Maximo", 1, 5.0);
    EXPECT_DOUBLE_EQ(e2.GetCalificacion(), 5.0);
}

TEST(EmptyStringTest, CamposVacios) {
    Pelicula p("", "", 0, "");
    EXPECT_TRUE(p.GetId().empty());
    EXPECT_TRUE(p.GetTitulo().empty());
    EXPECT_TRUE(p.GetGenero().empty());

    Episodio e("", 0, 0.0);
    EXPECT_TRUE(e.GetTitulo().empty());
}


TEST(EpisodioTest, MostrarInfoConDecimales) {
    Episodio e("Decimal Episode", 2, 4.375);
    testing::internal::CaptureStdout();
    e.MostrarInfo();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("4.375"), string::npos);
}

TEST(EpisodioTest, EpisodioSinTitulo) {
    Episodio e("", 1, 3.0);
    EXPECT_TRUE(e.GetTitulo().empty());
    e = Episodio("Non-empty", 1, 3.0);
    EXPECT_FALSE(e.GetTitulo().empty());
}