#include <iostream>
#include <sstream>
#include <string>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

using namespace std;

int
main(int argc, char **argv, char **envp)
{
    float x,y,z;
    string s;
    int i=0;
    glm::vec4 vertices[10];



    for(string line; getline(cin, line); ) {
        istringstream in(line);

        string type;
        float x, y, z;
        in >> x >> y >> z;    

	vertices[i++] = glm::vec4(x, y, z, 1.0f);
	cout<<glm::to_string(vertices[i-1])<<endl;
	if (i==4) break;
    }

    glm::mat4 m = glm::mat4(vertices[0], vertices[1], vertices[2], vertices[3]);
    cout<<glm::to_string(m)<<endl;

    glm::vec4 result = m * vertices[0];
    cout<<glm::to_string(result)<<endl;
    return 0;
}

