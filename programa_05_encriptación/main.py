import os

def cifrado_cesar(texto,desplazamiento):
    texto_encriptado = ""
    for caracter in texto:
        if caracter.isalpha():
            if caracter.isupper():
                texto_encriptado += chr((ord(caracter) + desplazamiento - 65) % 26 + 65)
            else:
                texto_encriptado += chr((ord(caracter) + desplazamiento - 97) % 26 + 97)
        else:
            texto_encriptado += caracter
    return texto_encriptado

def desencriptado_cesar(texto,desplazamiento):
    texto_desencriptado = ""
    for caracter in texto:
        if caracter.isalpha():
            if caracter.isupper():
                texto_desencriptado += chr((ord(caracter) - desplazamiento - 65) % 26 + 65)
            else:
                texto_desencriptado += chr((ord(caracter) - desplazamiento - 97) % 26 + 97)
        else:
            texto_desencriptado += caracter
    return texto_desencriptado

def cifrado_xor(texto,clave):
    texto_cifrado = ""
    for caracter in texto:
        texto_cifrado += chr(ord(caracter) ^ clave)
    return texto_cifrado

def main():
    opcion = input("¿Qué desea hacer? \n(1) Cifrar mensaje en un archivo \n(2) Descifrar mensaje de un archivo \ningrese opcion: ")
    os.system("cls")
    
    if opcion == "1":
        
        texto = input("Ingrese el mensaje a cifrar: ")
        metodo = input("\n¿Qué método desea utilizar? \n(1) Cifrado César \n(2) Cifrado XOR \ningrese opcion: ")
        
        if metodo == "1":
            print("\n----Cifrado César----")
            desplazamiento = int(input("Ingrese el desplazamiento: "))
            texto_cifrado = cifrado_cesar(texto,desplazamiento)
        elif metodo == "2":
            print("\n----Cifrado XOR----")
            clave = int(input("Ingrese la clave: "))
            texto_cifrado = cifrado_xor(texto,clave)
        
        print("\nEl mensaje cifrado es: ",texto_cifrado)
        
        try:
            file = open("message.txt","w")
            file.write(texto_cifrado)
            print("\nEl mensaje se ha guardado en el archivo message.txt")

        except IOError:
            print("\nError al abrir el archivo")
        finally:
            file.close()
        
        os.system("pause")
        os.system("cls")
    elif opcion == "2":

        try:
            file = open("message.txt","r")
            texto_cifrado = file.read()
            print("El mensaje cifrado es: ",texto_cifrado)
        except IOError:
            print("Error al abrir el archivo")
        finally:
            file.close()
        
        metodo = input("\n¿Qué método utilizó para cifrar el mensaje? \n(1) Cifrado César \n(2) Cifrado XOR \ningrese opcion: ")

        if metodo == "1":
            print("\n----Cifrado César----")
            desplazamiento = int(input("Ingrese el desplazamiento: "))
            texto_descifrado = desencriptado_cesar(texto_cifrado,desplazamiento)
        elif metodo == "2":
            print("\n----Cifrado XOR----")
            clave = int(input("Ingrese la clave: "))
            texto_descifrado = cifrado_xor(texto_cifrado,clave)
        print("\nEl mensaje descifrado es: ",texto_descifrado)
        os.system("pause")
        os.system("cls")

        print(""""
  ______                       __                                                                                                          __            __  __  __  __ 
 /      \                     /  |                                                                                                        /  |          /  |/  |/  |/  |
/$$$$$$  |  ______   __    __ $$/        _______    ______          ______    ______    _______   ______         _______    ______    ____$$ |  ______  $$ |$$ |$$ |$$ |
$$ |__$$ | /      \ /  |  /  |/  |      /       \  /      \        /      \  /      \  /       | /      \       /       \  /      \  /    $$ | /      \ $$ |$$ |$$ |$$ |
$$    $$ |/$$$$$$  |$$ |  $$ |$$ |      $$$$$$$  |/$$$$$$  |      /$$$$$$  | $$$$$$  |/$$$$$$$/ /$$$$$$  |      $$$$$$$  | $$$$$$  |/$$$$$$$ | $$$$$$  |$$ |$$ |$$ |$$ |
$$$$$$$$ |$$ |  $$ |$$ |  $$ |$$ |      $$ |  $$ |$$ |  $$ |      $$ |  $$ | /    $$ |$$      \ $$ |  $$ |      $$ |  $$ | /    $$ |$$ |  $$ | /    $$ |$$/ $$/ $$/ $$/ 
$$ |  $$ |$$ \__$$ |$$ \__$$ |$$ |      $$ |  $$ |$$ \__$$ |      $$ |__$$ |/$$$$$$$ | $$$$$$  |$$ \__$$ |      $$ |  $$ |/$$$$$$$ |$$ \__$$ |/$$$$$$$ | __  __  __  __ 
$$ |  $$ |$$    $$ |$$    $$/ $$ |      $$ |  $$ |$$    $$/       $$    $$/ $$    $$ |/     $$/ $$    $$/       $$ |  $$ |$$    $$ |$$    $$ |$$    $$ |/  |/  |/  |/  |
$$/   $$/  $$$$$$$ | $$$$$$/  $$/       $$/   $$/  $$$$$$/        $$$$$$$/   $$$$$$$/ $$$$$$$/   $$$$$$/        $$/   $$/  $$$$$$$/  $$$$$$$/  $$$$$$$/ $$/ $$/ $$/ $$/ 
                $$ |                                              $$ |                                                                                                  
                $$ |                                              $$ |                                                                                                  
                $$/                                               $$/                                                                                                   
        """)
        os.system("pause")
        

if __name__ == '__main__':
    main()