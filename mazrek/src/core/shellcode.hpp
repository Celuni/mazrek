#pragma once

namespace core
{
	BYTE shellcode_x86[]
	{
		0x60,							//pusha
		0x9C,							//pushf
		0xBB, 0xCC, 0xCC, 0xCC, 0xCC,	//mov ebx, 0xCCCCCCCC
		0x68, 0xCC, 0xCC, 0xCC, 0xCC,	//push 0xCCCCCCCC
		0xFF, 0xD3,						//call ebx 
		0x9D,							//popf 
		0x61,							//popa
		0xC3							//ret
	};

	BYTE shellcode_x64[] =
	{
		0x9C,	//pushfq
		0x50,	//push rax
		0x51,	//push rcx
		0x52,	//push rdx
		0x41, 0x50,	//push r8
		0x41, 0x51,	//push r9
		0x41, 0x52,	//push r10
		0x41, 0x53,	//push r11
		0x48, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	//mov rax, 0x0000000000000000
		0x48, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //mov rcx, 0x0000000000000000
		0x48, 0x83, 0xEC, 0x30,	//sub rsp, 0x30
		0xFF, 0xD0,				//call rax
		0x48, 0x83, 0xC4, 0x30,	//add rsp, 0x30
		0x41, 0x5B,	//pop r11
		0x41, 0x5A,	//pop r10
		0x41, 0x59,	//pop r9
		0x41, 0x58,	//pop r8
		0x5A,	//pop rdx
		0x59,	//pop rcx
		0x58,	//pop rax
		0x9D,	//popfq
		0xC3	//ret
	};
}

