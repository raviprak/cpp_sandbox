add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

add_executable(totw005 totw005.cc)
