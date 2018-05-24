uniform mat4 u_pvm_matrix;

attribute vec4 a_vertex;

void main() {
  gl_Position = u_pvm_matrix * a_vertex;
}
