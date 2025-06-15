
#include <gtest/gtest.h>
#include "clases.h"

TEST(VideoTest, CalificacionesValidas) {
    Pelicula p("P001", "Inception", 148, "accion");
    p.Calificar(3);
    p.Calificar(4);
    EXPECT_EQ(p.ObtenerCalPromedio(), 3.5);
}

TEST(VideoTest, CalificacionesInvalidas) {
    Pelicula p("P002", "Matrix", 120, "ciencia ficcion");
    p.Calificar(0);
    p.Calificar(6);
    EXPECT_EQ(p.ObtenerCalPromedio(), 0.0);
}

TEST(VideoTest, ConstructorVideo_MultipleInstancias) {

    string id1 = "P018";
    string titulo1 = "Ejemplo";
    double duracion1 = 120.0;
    string genero1 = "accion";

    Video* video1 = new Pelicula(id1, titulo1, duracion1, genero1);

    EXPECT_EQ(video1->GetTitulo(), titulo1);
    EXPECT_DOUBLE_EQ(video1->GetDuracion(), duracion1);
    EXPECT_EQ(video1->GetGenero(), genero1);

    string id2 = "P019";
    string titulo2 = "Otro Ejemplo";
    double duracion2 = 90.0;
    string genero2 = "drama";

    Video* video2 = new Pelicula(id2, titulo2, duracion2, genero2);

    EXPECT_EQ(video2->GetTitulo(), titulo2);
    EXPECT_DOUBLE_EQ(video2->GetDuracion(), duracion2);
    EXPECT_EQ(video2->GetGenero(), genero2);

}

TEST(VideoTest, CalificarValido) {
    Video* video = new Pelicula("V001", "Fast and Furious", 150.0, "accion");

    video->Calificar(4);
    EXPECT_EQ(video->ObtenerCalPromedio(), 4.0);

    video->Calificar(5);
    EXPECT_EQ(video->ObtenerCalPromedio(), 4.5);

}

TEST(VideoTest, CalificarInvalido) {
    Video* video = new Pelicula("V003", "Sonic", 120.0, "accion");

    video->Calificar(6);
    EXPECT_EQ(video->ObtenerCalPromedio(), 0.0);

    video->Calificar(0);
    EXPECT_EQ(video->ObtenerCalPromedio(), 0.0);

}

TEST(VideoTest, GetGenero_GetTitulo_MultipleVideos) {

    Pelicula p1("P001", "Inception", 148, "accion");
    Pelicula p2("P002", "Matrix", 120, "ciencia ficcion");

    EXPECT_EQ(p1.GetGenero(), "accion");
    EXPECT_EQ(p2.GetGenero(), "ciencia ficcion");

    EXPECT_EQ(p1.GetTitulo(), "Inception");
    EXPECT_EQ(p2.GetTitulo(), "Matrix");
}

TEST(VideoTest, PromedioConListaVacia) {
    Video* video = new Pelicula("P001", "Inception", 148, "accion");

    EXPECT_DOUBLE_EQ(video->ObtenerCalPromedio(), 0);

}

TEST(VideoTest, ConstructorInicializaAtributos) {
    Video* video = new Pelicula("P001", "Inception", 148, "accion");

    EXPECT_EQ(video->GetTitulo(), "Inception");
    EXPECT_EQ(video->GetGenero(), "accion");
    EXPECT_DOUBLE_EQ(video->GetDuracion(), 148);
    EXPECT_EQ(video->GetId(), "P001");

}

TEST(VideoTest, ConstructorConMultiplesInstancias) {
    Video* video1 = new Pelicula("P002", "El Padrino", 175, "drama");
    Video* video2 = new Serie("S001", "Stranger Things", 50, "misterio");

    EXPECT_EQ(video1->GetTitulo(), "El Padrino");
    EXPECT_EQ(video1->GetGenero(), "drama");
    EXPECT_DOUBLE_EQ(video1->GetDuracion(), 175);
    EXPECT_EQ(video1->GetId(), "P002");

    EXPECT_EQ(video2->GetTitulo(), "Stranger Things");
    EXPECT_EQ(video2->GetGenero(), "misterio");
    EXPECT_DOUBLE_EQ(video2->GetDuracion(), 50);
    EXPECT_EQ(video2->GetId(), "S001");

}