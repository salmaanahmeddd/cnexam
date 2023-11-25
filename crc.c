def generate_crc(data, divisor):
 data = list(data)
 divisor = list(divisor)
 divisor_length = len(divisor)
 # Append zeros to the data equal to the length of the divisor minus 1
 data += ['0'] * (divisor_length - 1)
 for i in range(len(data) - (divisor_length - 1)):
 if data[i] == '1':
 for j in range(divisor_length):
 data[i + j] = str(int(data[i + j]) ^ int(divisor[j]))
 return ''.join(data[-(divisor_length - 1):])
def inject_error(data, position):
 # Flip the bit at the specified position to simulate an error
 data_list = list(data)
 data_list[position] = str(1 - int(data_list[position]))
 return ''.join(data_list)
def detect_error(received_data, divisor):
 remainder = generate_crc(received_data, divisor)
def main():
 data = "11011010101100"
 divisor = "1011"
 crc_checksum = generate_crc(data, divisor)
 print(f"Sender Side:\nOriginal Data: {data}\nCRC Checksum: {crc_checksum}")
 error_position = 5
 received_data = inject_error(data, error_position)
 is_error = detect_error(received_data, divisor)
 print("\nReceiver Side:")
 print(f"Received Data: {received_data}")
 if is_error:
 print("Error detected: Yes")
 else:
 print("Error detected: No")
if __name__== "__main__":
 main()
