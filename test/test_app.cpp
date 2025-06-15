//
// Created by Annette on 14/06/2025.
//

#include <gtest/gtest.h>
#include "clases.h"
#include <vector>

TEST(AppTest, FiltrarPeliculasPorCalificacion) {
    vector<Video*> videos;

    Pelicula* p1 = new Pelicula("P001", "Inception", 148, "accion");
    p1->Calificar(5);
    p1->Calificar(5);

    Pelicula* p2 = new Pelicula("P002", "El Padrino", 175, "drama");
    p2->Calificar(4);
    p2->Calificar(3);

    videos.push_back(p1);
    videos.push_back(p2);

    testing::internal::CaptureStdout();
    for (auto vid : videos) {
        Pelicula* p = dynamic_cast<Pelicula*>(vid);
        if (p && p->ObtenerCalPromedio() >= 4.5)
            p->MostrarInfo();
    }
    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Inception"), string::npos);
    EXPECT_EQ(output.find("El Padrino"), string::npos);

    delete p1;
    delete p2;
}

TEST(VirtualMethodsTest, Polimorfismo) {
    Video* v1 = new Pelicula("mov009", "Poly Movie", 120, "Test");
    Video* v2 = new Serie("ser011", "Poly Serie", 30, "Test");

    testing::internal::CaptureStdout();
    v1->MostrarInfo();
    string output1 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output1.find("Pelicula:"), string::npos);

    testing::internal::CaptureStdout();
    v2->MostrarInfo();
    string output2 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output2.find("Serie:"), string::npos);

    delete v1;
    delete v2;
}

TEST(CoverageTest, VideoMetodosVirtuales) {
    Video* v = new Serie("ser016", "Virtual Test", 30, "Test");
    delete v;

    v = new Pelicula("mov014", "Virtual Test", 110, "Test");
    delete v;
}

TEST(CoverageTest, EpisodioCopias) {
    Episodio e1("Original", 1, 4.0);
    Episodio e2 = e1;

    EXPECT_EQ(e1.GetTitulo(), e2.GetTitulo());
    EXPECT_EQ(e1.GetTemporada(), e2.GetTemporada());
    EXPECT_DOUBLE_EQ(e1.GetCalificacion(), e2.GetCalificacion());
}

TEST(CoverageTest, SerieAsignacion) {
    Serie s1("ser017", "Source", 40, "Test");
    s1.AgregarEpisodio(Episodio("Ep", 1, 4.0));

    Serie s2("ser018", "Dest", 50, "Test2");
    s2 = s1;

    EXPECT_EQ(s2.GetId(), "ser017");
    EXPECT_EQ(s2.GetEpisodios().size(), 1);
}