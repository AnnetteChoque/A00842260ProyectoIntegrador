
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

class Video {
protected:
    string id, titulo, genero;
    double duracion;
    vector<int> calificacion;

public:
    Video(string id, string titulo, double duracion, string genero)
        : id(id), titulo(titulo), duracion(duracion), genero(genero) {}

    virtual ~Video() {}

    void calificar(int calif) {
        if (calif >= 1 && calif <= 5) {
            calificacion.push_back(calif);
        }
    }

    double obtenerCalPromedio() const {
        if (calificacion.empty()) {
            return 0;
        }
        return accumulate(calificacion.begin(), calificacion.end(), 0.0) / calificacion.size();
    }

    string getGenero() const {
        return genero;
    }

    string getTitulo() const {
        return titulo;
    }

    virtual void mostrarInfo() const = 0;
};

class Pelicula : public Video {
public:
    Pelicula(string id, string titulo, double duracion, string genero)
        : Video(id, titulo, duracion, genero) {}

    void mostrarInfo() const override {
        cout << "Pelicula: " << titulo << "\nDuracion: " << duracion
        << "\nGenero: " << genero << "\nCalificacion: "
        << obtenerCalPromedio() << endl;
    }
};

class Episodio {
private:
    string titulo;
    int temporada;
    double calificacion;

public:
    Episodio(string titulo, int temporada, double calificacion = 0)
        : titulo(titulo), temporada(temporada), calificacion(calificacion) {}

    void mostrarInfo() const {
        cout << "Episodio: " << titulo << "\nTemporada " << temporada
        << "\nCalificacion: " << calificacion << endl;
    }

    double getCalificacion() const {
        return calificacion;
    }
};

class Serie : public Video {
private:
    vector<Episodio> episodios;

public:
    Serie(string id, string titulo, double duracion, string genero)
        : Video(id, titulo, duracion, genero) {}

    void agregarEpisodio(const Episodio &ep) {
        episodios.push_back(ep);
    }

    void mostrarInfo() const override {
        cout << "Serie: " << titulo
        << "\nGenero: " << genero
        << "\nCalificacion: " << obtenerCalPromedio() << endl;
    }

    void mostrarEpsCalificados(double calif) const {
        for (const auto& ep : episodios) {
            if (ep.getCalificacion() >= calif)
                ep.mostrarInfo();
        }
    }
};

#endif //CLASES_H
