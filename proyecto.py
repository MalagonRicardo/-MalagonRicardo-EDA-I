inventory = []

def add_supplies():
    code = input("Ingrese el código del suministro: ")
    name = input("Ingrese el nombre del suministro: ")

    item = {"code": code, "name": name}
    inventory.append(item)

    print("Suministro agregado correctamente.")

def remove_supplies():
    code = input("Ingrese el código del suministro a eliminar: ")

    found_item = None
    for item in inventory:
        if item["code"] == code:
            found_item = item
            break

    if found_item:
        inventory.remove(found_item)
        print("Suministro eliminado correctamente.")
    else:
        print("El suministro con el código ingresado no se encuentra en el inventario.")

def sort_supplies():
    choice = input("Criterio de orden:\n1. Nombre\n2. Código\nIngrese su elección: ")

    if choice == '1':
        inventory.sort(key=lambda item: item["name"])
    elif choice == '2':
        inventory.sort(key=lambda item: item["code"])
    else:
        print("Opción inválida.")
        return

    print("Suministros ordenados correctamente.")

def inventory_management_menu():
    while True:
        print("\n--- Administración de Inventario ---")
        print("1. Añadir suministros")
        print("2. Quitar suministros")
        print("3. Ordenar suministros")
        print("0. Volver al menú principal")
        choice = input("Ingrese su elección: ")

        if choice == '1':
            add_supplies()
        elif choice == '2':
            remove_supplies()
        elif choice == '3':
            sort_supplies()
        elif choice == '0':
            print("Volviendo al menú principal...")
            break
        else:
            print("Opción inválida.")

def customer_service_menu():
    # Aqui faltan las funciones para la atención a clientes
    print("--- Atención a Clientes ---")
    print("Funcionalidad en desarrollo...")

def personnel_management_menu():
    # Aqui faltan las funciones para la administración de personal 
    print("--- Administración de Personal ---")
    print("Funcionalidad en desarrollo...")

def main():
    while True:
        print("\n---- Menú Principal ----")
        print("Opciones:")
        print("1. Administración de Inventario")
        print("2. Atención a Clientes")
        print("3. Administración de Personal")
        print("0. Salir")
        choice = input("Ingrese su elección: ")

        if choice == '1':
            inventory_management_menu()
        elif choice == '2':
            customer_service_menu()
        elif choice == '3':
            personnel_management_menu()
        elif choice == '0':
            print("Saliendo...")
            break
        else:
            print("Opción inválida.")

if __name__ == '__main__':
    main()

