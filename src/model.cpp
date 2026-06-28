#include "model.h"
#include <array>
#include <fstream>
#include <sstream>
#include <vector>

struct Vec3 {
    GLfloat x;
    GLfloat y;
    GLfloat z;
};

struct ObjVertexRef {
    int vertex = -1;
    int normal = -1;
};

struct ObjModel {
    std::vector<Vec3> vertices;
    std::vector<Vec3> normals;
    std::vector<std::array<ObjVertexRef, 3> > triangles;
};

static int parseObjIndex(const std::string& value, int count)
{
    if (value.empty()) return -1;
    int index = std::stoi(value);
    if (index > 0) return index - 1;
    if (index < 0) return count + index;
    return -1;
}

static ObjVertexRef parseFaceToken(const std::string& token,
                                   int vertexCount,
                                   int normalCount)
{
    ObjVertexRef ref;
    std::size_t firstSlash = token.find('/');

    if (firstSlash == std::string::npos) {
        ref.vertex = parseObjIndex(token, vertexCount);
        return ref;
    }

    ref.vertex = parseObjIndex(token.substr(0, firstSlash), vertexCount);

    std::size_t secondSlash = token.find('/', firstSlash + 1);
    if (secondSlash != std::string::npos) {
        ref.normal = parseObjIndex(token.substr(secondSlash + 1), normalCount);
    }

    return ref;
}

ObjModel* loadObjModel(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file) return nullptr;

    ObjModel* model = new ObjModel();
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream in(line);
        std::string type;
        in >> type;

        if (type == "v") {
            Vec3 vertex;
            in >> vertex.x >> vertex.y >> vertex.z;
            model->vertices.push_back(vertex);
        } else if (type == "vn") {
            Vec3 normal;
            in >> normal.x >> normal.y >> normal.z;
            model->normals.push_back(normal);
        } else if (type == "f") {
            std::vector<ObjVertexRef> refs;
            std::string token;
            while (in >> token) {
                refs.push_back(parseFaceToken(token,
                                              static_cast<int>(model->vertices.size()),
                                              static_cast<int>(model->normals.size())));
            }

            if (refs.size() >= 3) {
                for (std::size_t i = 1; i + 1 < refs.size(); ++i) {
                    model->triangles.push_back({ refs[0], refs[i], refs[i + 1] });
                }
            }
        }
    }

    if (model->vertices.empty() || model->triangles.empty()) {
        delete model;
        return nullptr;
    }

    return model;
}

void drawObjModel(const ObjModel& model,
                  GLfloat r, GLfloat g, GLfloat b,
                  GLfloat shine)
{
    GLfloat noMat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat ambient[] = { r * 0.18f, g * 0.18f, b * 0.18f, 1.0f };
    GLfloat diffuse[] = { r, g, b, 1.0f };
    GLfloat specular[] = { 0.55f, 0.55f, 0.55f, 1.0f };
    GLfloat shininess[] = { shine };

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, noMat);

    glBegin(GL_TRIANGLES);
    for (const auto& triangle : model.triangles) {
        for (const auto& ref : triangle) {
            if (ref.normal >= 0 && ref.normal < static_cast<int>(model.normals.size())) {
                const Vec3& normal = model.normals[ref.normal];
                glNormal3f(normal.x, normal.y, normal.z);
            }

            if (ref.vertex >= 0 && ref.vertex < static_cast<int>(model.vertices.size())) {
                const Vec3& vertex = model.vertices[ref.vertex];
                glVertex3f(vertex.x, vertex.y, vertex.z);
            }
        }
    }
    glEnd();
}
