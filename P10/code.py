biblioteca = []

def agregar_libro():
    titulo = input("Ingrese el título del libro: ")
    biblioteca.append(titulo)
    print("Libro agregado correctamente.")

def eliminar_libro():
    titulo = input("Ingrese el título del libro a eliminar: ")
    if titulo in biblioteca:
        biblioteca.remove(titulo)
        print("Libro eliminado correctamente.")
    else:
        print("El libro no se encuentra en la biblioteca.")

def ordenar_biblioteca():
    biblioteca.sort()
    print("Biblioteca ordenada correctamente.")

def ver_biblioteca():
    if biblioteca:
        print("Biblioteca:")
        for libro in biblioteca:
            print(libro)
    else:
        print("La biblioteca está vacía.")

def mostrar_menu():
    print("\nMenú:")
    print("1 - Agregar libro")
    print("2 - Eliminar libro")
    print("3 - Ordenar biblioteca")
    print("4 - Ver biblioteca")
    print("5 - Salir")
    opcion = input("Seleccione una opción: ")
    return opcion

def main():
    opcion = mostrar_menu()

    while opcion != "5":
        if opcion == "1":
            agregar_libro()
        elif opcion == "2":
            eliminar_libro()
        elif opcion == "3":
            ordenar_biblioteca()
        elif opcion == "4":
            ver_biblioteca()
        
        opcion = mostrar_menu()

    print("Programa finalizado.")

if __name__ == "__main__":
    main()
