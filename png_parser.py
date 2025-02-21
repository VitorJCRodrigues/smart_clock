from PIL import Image
import sys
import os

# Define the number of LEDs
NUM_LEDS = 25

def load_image_to_led_image(image_path):
    # Open the image
    try:
        img = Image.open(image_path)
    except FileNotFoundError:
        print(f"Error: The file '{image_path}' does not exist.")
        sys.exit(1)
    except Exception as e:
        print(f"Error: Unable to open the image. {e}")
        sys.exit(1)

    # Verify the image size
    if img.size != (5, 5):
        print("Error: The image must be exactly 5x5 pixels.")
        sys.exit(1)

    # Flip the image vertically
    img = img.transpose(Image.FLIP_TOP_BOTTOM)

    # Convert the image to RGB
    img = img.convert("RGB")

    # Extract pixel data
    pixels = img.load()
    red = []
    green = []
    blue = []
    for y in range(5):
        for x in range(5):
            r, g, b = pixels[x, y]
            red.append(r)
            green.append(g)
            blue.append(b)

    return red, green, blue

def generate_c_header(red, green, blue, output_file, struct_name):
    # Write the C header file
    with open(output_file, "w") as f:
        f.write('#include "rgb_img.h"\n\n')
        f.write(f"Led_Image {struct_name} = {{\n")
        f.write("    .red = {")
        f.write(", ".join(map(str, red)))
        f.write("},\n")
        f.write("    .green = {")
        f.write(", ".join(map(str, green)))
        f.write("},\n")
        f.write("    .blue = {")
        f.write(", ".join(map(str, blue)))
        f.write("}\n")
        f.write("};\n")

def main():
    # Check if the image path is provided as an argument
    if len(sys.argv) < 2:
        print("Usage: python script.py <image_path> [output_header_file]")
        sys.exit(1)

    image_path = sys.argv[1]

    # If no output file is provided, default to the input file name with .h extension
    if len(sys.argv) == 2:
        output_file = os.path.splitext(image_path)[0] + ".h"
    else:
        output_file = sys.argv[2]

    # Extract the struct name from the input file name (without extension)
    struct_name = os.path.splitext(os.path.basename(image_path))[0]

    # Load the image and extract RGB values
    red, green, blue = load_image_to_led_image(image_path)

    # Generate the C header file
    generate_c_header(red, green, blue, output_file, struct_name)
    print(f"C header file '{output_file}' generated successfully with struct name '{struct_name}'.")

if __name__ == "__main__":
    main()