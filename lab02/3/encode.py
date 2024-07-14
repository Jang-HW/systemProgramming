# 메시지를 암호화하여 파일에 저장하는 코드
message = "Hell¤o all~! I ŗlove» System Proȷgr¥amming :)"
encrypted_bytes = []

for char in message:
    ascii_value = ord(char)
    if 32 <= ascii_value <= 127:
        encrypted_bytes.append(ascii_value)
    else:
        jump = ascii_value % 32
        for _ in range(jump):
            encrypted_bytes.append(0)  # 무의미한 값(0) 삽입

# 파일에 저장
with open('./message.txt', 'wb') as file:
    file.write(bytes(encrypted_bytes))
