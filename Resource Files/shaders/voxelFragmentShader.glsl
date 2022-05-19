#version 400

in vec4 out_f_color;
in vec2 out_f_uv;

out vec4 frag_color;

uniform sampler2D tex;

vec2 v2len(in vec2 a, in vec2 b) {
    return sqrt(a * a + b * b);
}

vec2 uv_blocky(in vec2 uv, in ivec2 res) {
    vec2 pixels = uv * res; // enter texel coordinate space.

    vec2 seam = floor(pixels + .5); // find the nearest seam between texels.

    // here's where the magic happens. scale up the distance to the seam so that all
    // interpolation happens in a one-pixel-wide space.
    pixels = (pixels - seam) / v2len(dFdx(pixels), dFdy(pixels)) + seam;

    pixels = clamp(pixels, seam - .5, seam + .5); // clamp to the center of a texel.

    return(pixels / res); // convert back to 0..1 coordinate space.
}

void main()
{
	frag_color = out_f_color;
};
