// DX21 Vertex Shader Sample Ver.2 - Texture 

// Structures
// OUTPUT: used to store values that are returned at the end of vs_main
struct OUTPUT {
	float4 pos : SV_POSITION;
	float2 tex : TEXCOORD;
};

// Vertex shader entrypoint function
// Return value: an instance of OUTPUT structure that holds a set of positions & UVs
// Argument inputPos: Vertex's position - xyzw
// Argument inputTex: Texture coordinates (UV values) 
OUTPUT vs_main(float4 inputPos : POSITION, float2 inputTex : TEXCOORD)
{
	OUTPUT output;

	output.pos = inputPos;
	output.tex = inputTex;

    return output;
}