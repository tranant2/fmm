inc = include_directories('.')

tree = library('node', sources: ['QTNode.hpp', 'Quadtree.h','Quadtree.cpp'])
tree_dep = declare_dependency(include_directories: inc,
  link_with: tree)

fmm = executable('fmm', 
    sources : ['main.cpp'],
    dependencies : [tree_dep],
    install : true)
