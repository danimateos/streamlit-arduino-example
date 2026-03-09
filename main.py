import streamlit as st
import serial
from serial.tools import list_ports

st.title("Hello from Barcelona!")

name = st.text_input("tell me your name")

if name:
    st.write(f"Hello, {name}!")

# List available serial ports
ports = list_ports.comports()
port_list = [port.device for port in ports]

port = st.selectbox("Select a serial port", options=port_list, index=None)

if port:
    try:
        ser = serial.Serial(port, 9600, timeout=1)
        st.write(f"Connected to {port}")
        ser.close()
    except serial.SerialException as e:
        st.error(f"Could not connect to {port}: {e}")


