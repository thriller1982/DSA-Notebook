add_executable(heap_demo
    heap_demo.c
)

target_link_libraries(heap_demo PRIVATE
    binary_heap
)
