# Garbage Classification Device at Embedded AI Summer School 2021 of Nanjing IC Training Base
1. Based on garbage datasets online, apply TensorFlow to get and expand images' feathers, set the parameters such as mode, batch size, ReLU, and then create CNN for training. Check the satisfying accuracy by matplotlib, then save the model as a h5 file (tflite is also suitable).
2. Use AI-Tool to load the file and related configuration to ART-Pi, and then design the driver codes. After initialising the screen, camera, and so on, use the bilinear interpolation to convert captured images to particular three-channel data according to the model. Finally, relying on objects predicted, there will be some corresponding reaction in the board.
3. Help with the presentation, on-site installation and demonstration of this program, answered the questions about system design from the judges.

And you can view a [demo](https://www.bilibili.com/video/BV1fg411K7kh?spm_id_from=333.999.0.0) of the device on Bilibili.
