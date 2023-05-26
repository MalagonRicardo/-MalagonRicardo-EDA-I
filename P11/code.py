def decimal_a_binario(n):
    if n == 0:
        return '0'
    elif n == 1:
        return '1'
    else:
        return decimal_a_binario(n // 2) + str(n % 2) 


def fibonacci(n):
    if n <= 0:
        return []
    elif n == 1:
        return [0]
    elif n == 2:
        return [0, 1]
    else:
        fibo = fibonacci(n - 1)
        fibo.append(fibo[-1] + fibo[-2])
        return fibo

def imprimirReversed(lista):
    for i in range(len(lista)-1, -1, -1):
        print(lista[i], end=" ")



def main():
    while True:
        print("Menú de opciones:")
        print("1 - Conversión de bases")
        print("2 - Serie de Fibonacci")
        print("3 - Salir")

        opcion = input("Ingrese su opción: ")

        if opcion == '1':
            n = int(input("Ingrese el número entero N: "))
            resultado = decimal_a_binario(n)
            print(f"El número binario equivalente es: {resultado}\n")
        elif opcion == '2':
            n = int(input("Ingrese el valor de N: "))
            fibonacci_seq = fibonacci(n)
            print("Los primeros", n, "términos de la serie de Fibonacci en orden inverso son:")
            imprimirReversed(fibonacci_seq)
            print("\n")
        elif opcion == '3':
            print("xD")
            break
        else:
            print("Opción inválida. Por favor, ingrese una opción válida.\n")


if __name__ == "__main__":
    main()
