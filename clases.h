
/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef CLASES_H
#define CLASES_H

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

/**
 * Video
 * Clase base abstracta que representa un video (película o serie)
 */
class Video {
protected:
    /// @brief Identificador único del video
    string id;
    /// @brief Título del video
    string titulo;
    /// @brief Duración del video en minutos
    double duracion;
    /// @brief Género del video
    string genero;
    /// @brief Calificaciones recibidas por el video (rango: 1 a 5)
    vector<int> calificacion;

public:
    /**
     * Constructor de la clase Video
     * _id Identificador único del video
     *  _titulo Título del video
     * _duracion Duración del video en minutos
     * _genero Género del video
     */
    Video(string _id, string _titulo, double _duracion, string _genero) : id(_id), titulo(_titulo), duracion(_duracion), genero(_genero) {}
    /**
         * @brief Destructor virtual de la clase Video
         */
    virtual ~Video() {}

    /**
     * Añade una calificación al video
     * calif Calificación entre 1 y 5
     */
    void Calificar(int calif) {
        if (calif >= 1 && calif <= 5) {
            calificacion.push_back(calif);
        }
    }

    /**
     * Calcula la calificación promedio del video
     * Promedio de calificaciones, o 0 si no tiene calificaciones
     */
    double ObtenerCalPromedio() const {
        if (calificacion.empty()) {
            return 0;
        }
        return accumulate(calificacion.begin(), calificacion.end(), 0.0) / calificacion.size();
    }

    /**
     * Obtiene el género del video
     * Cadena con el género
     */
    string GetGenero() const {
        return genero;
    }

    /**
     * Obtiene el título del video
     * Cadena con el título
     */
    string GetTitulo() const {
        return titulo;
    }

    /**
     * Muestra la información del video (método abstracto)
     */
    virtual void MostrarInfo() const = 0;
};

/**
 * Pelicula
 * Representa una película, derivada de Video
 */
class Pelicula : public Video {
public:
    /**
     * Constructor de la clase Pelicula
     * _id Identificador único de la película
     * _titulo Título de la película
     * _duracion Duración de la película en minutos
     * _genero Género de la película
     */
    Pelicula(string _id, string _titulo, double _duracion, string _genero) : Video(_id, _titulo, _duracion, _genero) {}

    /**
     * Muestra la información de la película
     */
    void MostrarInfo() const override {
        cout << "Pelicula: " << titulo << "\nDuracion: " << duracion
             << "\nGenero: " << genero << "\nCalificacion: "
             << ObtenerCalPromedio() << endl;
    }
};

/**
 * Episodio
 * Representa un episodio de una serie
 */
class Episodio {
private:
    ///< Título del episodio
    string titulo;

    ///< Número de temporada a la que pertenece
    int temporada;

    ///< Calificación del episodio (rango: 1 a 5)
    double calificacion;

public:
    /**
     * Constructor de la clase Episodio
     * _titulo Título del episodio
     * _temporada Temporada a la que pertenece
     * _calificacion Calificación inicial del episodio
     */
    Episodio(string _titulo, int _temporada, double _calificacion = 0) : titulo(_titulo), temporada(_temporada), calificacion(_calificacion) {}

    /**
     * Muestra la información del episodio
     */
    void MostrarInfo() const {
        cout << "Episodio: " << titulo << "\nTemporada: " << temporada
             << "\nCalificacion: " << calificacion << endl;
    }

    /**
     * Obtiene la calificación del episodio
     * Calificación actual del episodio
     */
    double GetCalificacion() const {
        return calificacion;
    }
};

/**
 * Serie
 * Representa una serie, derivada de Video, contiene varios episodios
 */
class Serie : public Video {
private:
    ///< Lista de episodios de la serie
    vector<Episodio> episodios;

public:
    /**
     * Constructor de la clase Serie
     * _id Identificador único de la serie
     * _titulo Título de la serie
     * duracion Duración promedio de los episodios
     *  _genero Género de la serie
     */
    Serie(string _id, string _titulo, double _duracion, string _genero) : Video(_id, _titulo, _duracion, _genero) {}

    /**
     * Agrega un nuevo episodio a la serie
     * ep Episodio a agregar
     */
    void AgregarEpisodio(const Episodio &ep) {
        episodios.push_back(ep);
    }

    /**
     * Muestra la información general de la serie
     */
    void MostrarInfo() const override {
        cout << "Serie: " << titulo
             << "\nGenero: " << genero
             << "\nCalificacion: " << ObtenerCalPromedio() << endl;
    }

    /**
     * Muestra los episodios con calificación mayor o igual a una dada
     * calif Calificación mínima a mostrar
     */
    void MostrarEpsCalificados(double calif) const {
        for (const auto& ep : episodios) {
            if (ep.GetCalificacion() >= calif) {
                ep.MostrarInfo();
            }
        }
    }
};

#endif // CLASES_H
