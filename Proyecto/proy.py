inventory = []
lista = []
problemas = []
staff = []

def add_supplies():
    code = input("\nIngrese el código del suministro: ")
    name = input("Ingrese el nombre del suministro: ")
    price = input("Ingrese el precio del suministro: ")

    item = [code, name, price]
    inventory.append(item)

    for x in range(0, len(inventory)):
        print(inventory[x][0] + " - " + inventory[x][1])

    print("Suministro agregado correctamente.")

def remove_supplies():
    code = input("\nIngrese el código del suministro a eliminar: ")

    found_item = None
    for x in range(0, len(inventory)):
        if inventory[x][0] == code:
            found_item = inventory[x]
            break

    if found_item:
        inventory.remove(found_item)
        print("Suministro eliminado correctamente.")
    else:
        print("El suministro con el código ingresado no se encuentra en el inventario.")

def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    left_half = merge_sort(left_half)
    right_half = merge_sort(right_half)

    return merge(left_half, right_half)


def merge(left, right):
    merged = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1

    while i < len(left):
        merged.append(left[i])
        i += 1

    while j < len(right):
        merged.append(right[j])
        j += 1

    return merged

def sort_supplies():
    choice = input("\nCriterio de orden:\n1. Nombre\n2. Código\nIngrese su elección: ")

    if choice == '1':

        var0 = 0

        while var0 < len(inventory):

            temp = inventory[var0][0]
            inventory[var0][0] = inventory[var0][1]
            inventory[var0][1] = temp 

            var0+=1

        lista = merge_sort(inventory)

        var1 = 0

        while var1 < len(inventory):

            temp = lista[var1][0]
            lista[var1][0] = lista[var1][1]
            lista[var1][1] = temp 

            var1+=1

        for x in range(0 , len(lista)):
            print(lista[x][0] + " - " + lista[x][1])

        for y in range(0 , len(lista)):
            inventory[y] = lista[y]

    elif choice == '2':

        lista = merge_sort(inventory)
        
        for x in range(0, len(lista)):
            print(lista[x][0] + " - " + lista[x][1])

        for y in range(0, len(lista)):
            inventory[y] = lista[y]


    else:
        print("Opción inválida.")
        return

    print("Suministros ordenados correctamente.")

def charge_products():

    addition = 0

    print("\n1. Cobrar por código")
    print("2. Cobrar por nombre")
    elec = input("Ingrese su elección: ")

    if elec == '1':

        condition = '1'

        while condition != '0':

            code = input("Digite el código del suministro que desea comprar: ")

            cont = 0

            for x in range(0, len(inventory)):
                if code == inventory[x][0]:
                    print("Código del suministro: " + inventory[x][0])
                    print("Nombre del suministro: "+ inventory[x][1])
                    print("Precio del suministro: $" + inventory[x][2])

                    addition = float(inventory[x][2]) + addition
                    round(addition, 2)

                    cont+=1

                    condition = input("Para dejar de comprar digite 0, caso contrario digite cualquier otro caracter: ")
                
            if cont == 0:
                print("No se encontro el suministro con el código dado, por favor digite un nuevo codigo.")

                while True:

                    print("1. Ver códigos válidos")
                    print("2. Volver a introducir código")
                    elec = input("Ingrese su elección: ")

                    if elec == '1':
                        for x in range(0, len(inventory)):
                            print(inventory[x][0])
                    elif elec == '2':
                        break
                    else:
                        print("Opción invalida")
               

        print(f"El total de la compra es de: ${addition}")
    
    elif elec == '2':

        condition = '1'

        while condition != '0':

            name = input("Escriba el nombre del suministro que desea comprar: ")

            cont = 0

            for x in range(0, len(inventory)):
                if name == inventory[x][1]:
                    print("Código del suministro: " + inventory[x][0])
                    print("Nombre del suministro: "+ inventory[x][1])
                    print("Precio del suministro: $" + inventory[x][2])

                    addition = float(inventory[x][2]) + addition
                    round(addition, 2)

                    cont+=1

                    condition = input("Para dejar de comprar digite 0, caso contrario digite cualquier otro caracter: ")
                
            if cont == 0:
                print("No se encontro el suministro con el nombre dado, por favor digite un nuevo nombre.")

                while True:

                    print("1. Ver nombres válidos")
                    print("2. Volver a introducir nombre")
                    elec = input("Ingrese su elección: ")

                    if elec == '1':
                        for x in range(0, len(inventory)):
                            print(inventory[x][1])
                    elif elec == '2':
                        break
                    else:
                        print("Opción invalida")

            
        print(f"El total de la compra es de: ${addition}")

    else:
        print("Opción inválida.")


def problems_support():

    condition = '1'

    while condition != '0':

        code = input("\nPor favor ingrese el código del suministro sobre el que tiene algún problema: ")

        cont = 0

        for x in range(0, len(inventory)):
            if code == inventory[x][0]:
                print("Código del suministro: " + inventory[x][0])
                print("Nombre del suministro: "+ inventory[x][1])
                print("Precio del suministro: $" + inventory[x][2])

                name = inventory[x][1]

                cont+=1
            
        if cont == 0:
            print("No se encontro el suministro con el código dado, por favor digite un nuevo codigo.")

            while True:

                    print("1. Ver códigos válidos")
                    print("2. Volver a introducir código")
                    elec = input("Ingrese su elección: ")

                    if elec == '1':
                        for x in range(0, len(inventory)):
                            print(inventory[x][0])
                    elif elec == '2':
                        break
                    else:
                        print("Opción invalida")


        elif cont == 1:
            prob = input("Escriba el problema que tiene con el producto: ")

            item = [code, name, prob]

            problemas.append(item)

            condition = input("Si tiene algun otro problema digite cualquier número diferente a 0, para salir digite 0: ")

def see_problems():
    print("\nLos problemas de los clientes con los productos son los siguientes: ")
    
    for x in range(0, len(problemas)):
        print("Código: " + problemas[x][0] + " - " + problemas[x][1] + "  Problema: " + problemas[x][2])

def register():

    ide = input("\nIngrese el id del trabajador que va a registrar: ")
    name = input("Ingrese el nombre del trabajador que va a registrar: ")
    position = input("Ingrese el puesto del trabajador que va a registrar: ")

    item = [ide, name, position]

    staff.append(item)

def terminate():

    ide = input("\nIngrese el id del trabajador que desea dar de baja: ")

    for x in range(0, len(staff)):
        if ide == staff[x][0]:
            found_id = staff[x]
            break
    
    staff.remove(found_id)
    print("\nSe ha dado de baja al trabajador de manera correcta.")


def change_position():
    ide = input("\nIngrese el id del trabajador al cual desea cambiar de posición: ")

    for x in range(0, len(staff)):
        if ide == staff[x][0]:
            new_position = input("Ingrese la nueva posición del trabajador: ")

            staff[x][2] = new_position

            print("La posición del trabajador ha cambiado correctamente.")

def see_staff():

    print("\n")

    for x in range(0, len(staff)):
        print("ID: " + staff[x][0] + " - Nombre: " + staff[x][1] + " - Posición: " + staff[x][2])
        




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
    
    while True:

        print("\n--- Atención a Clientes ---")
        print("1. Cobrar productos")
        print("2. Atención a problemas")
        print("3. Ver problemas")
        print("0. Volver al menú principal")

        choice = input("Ingrese su elección: ")

        if choice == '1':
            charge_products()
        elif choice == '2':
            problems_support()
        elif choice == '3':
            see_problems()
        elif choice == '0':
            print("Volviendo al menú principal...")
            break
        else:
            print("Opcion inválida")


def staff_management_menu():

    while True:

        print("\n--- Administración de Personal ---")
        print("Opciones: ")
        print("1. Altas")
        print("2. Bajas")
        print("3. Cambio de puesto")
        print("4. Ver trabajadores")
        print("0. Volver al menú principal")
        choice = input("Ingrese su elección: ")

        if choice == '1':
            register()
        elif choice == '2':
            terminate()
        elif choice == '3':
            change_position()
        elif choice == '4':
            see_staff()
        elif choice == '0':
            print("Volviendo al menú principal...")
            break
        else:
            print("Opción invalida")
        

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
            staff_management_menu()
        elif choice == '0':
            print("Saliendo...")
            break
        else:
            print("Opción inválida.")

if __name__ == '__main__':
    main()