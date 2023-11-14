
guess:     file format elf64-x86-64


Disassembly of section .interp:

0000000000000318 <.interp>:
 318:	2f                   	(bad)  
 319:	6c                   	ins    BYTE PTR es:[rdi],dx
 31a:	69 62 36 34 2f 6c 64 	imul   esp,DWORD PTR [rdx+0x36],0x646c2f34
 321:	2d 6c 69 6e 75       	sub    eax,0x756e696c
 326:	78 2d                	js     355 <_init-0xcab>
 328:	78 38                	js     362 <_init-0xc9e>
 32a:	36 2d 36 34 2e 73    	ss sub eax,0x732e3436
 330:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 331:	2e 32 00             	xor    al,BYTE PTR cs:[rax]

Disassembly of section .note.gnu.property:

0000000000000338 <.note.gnu.property>:
 338:	04 00                	add    al,0x0
 33a:	00 00                	add    BYTE PTR [rax],al
 33c:	10 00                	adc    BYTE PTR [rax],al
 33e:	00 00                	add    BYTE PTR [rax],al
 340:	05 00 00 00 47       	add    eax,0x47000000
 345:	4e 55                	rex.WRX push rbp
 347:	00 02                	add    BYTE PTR [rdx],al
 349:	00 00                	add    BYTE PTR [rax],al
 34b:	c0 04 00 00          	rol    BYTE PTR [rax+rax*1],0x0
 34f:	00 03                	add    BYTE PTR [rbx],al
 351:	00 00                	add    BYTE PTR [rax],al
 353:	00 00                	add    BYTE PTR [rax],al
 355:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .note.gnu.build-id:

0000000000000358 <.note.gnu.build-id>:
 358:	04 00                	add    al,0x0
 35a:	00 00                	add    BYTE PTR [rax],al
 35c:	14 00                	adc    al,0x0
 35e:	00 00                	add    BYTE PTR [rax],al
 360:	03 00                	add    eax,DWORD PTR [rax]
 362:	00 00                	add    BYTE PTR [rax],al
 364:	47                   	rex.RXB
 365:	4e 55                	rex.WRX push rbp
 367:	00 89 5e c6 44 cf    	add    BYTE PTR [rcx-0x30bb39a2],cl
 36d:	ad                   	lods   eax,DWORD PTR ds:[rsi]
 36e:	bb 22 95 68 b6       	mov    ebx,0xb6689522
 373:	4f d5                	rex.WRXB (bad) 
 375:	95                   	xchg   ebp,eax
 376:	e7 91                	out    0x91,eax
 378:	b4 a0                	mov    ah,0xa0
 37a:	51                   	push   rcx
 37b:	18                   	.byte 0x18

Disassembly of section .note.ABI-tag:

000000000000037c <.note.ABI-tag>:
 37c:	04 00                	add    al,0x0
 37e:	00 00                	add    BYTE PTR [rax],al
 380:	10 00                	adc    BYTE PTR [rax],al
 382:	00 00                	add    BYTE PTR [rax],al
 384:	01 00                	add    DWORD PTR [rax],eax
 386:	00 00                	add    BYTE PTR [rax],al
 388:	47                   	rex.RXB
 389:	4e 55                	rex.WRX push rbp
 38b:	00 00                	add    BYTE PTR [rax],al
 38d:	00 00                	add    BYTE PTR [rax],al
 38f:	00 03                	add    BYTE PTR [rbx],al
 391:	00 00                	add    BYTE PTR [rax],al
 393:	00 02                	add    BYTE PTR [rdx],al
 395:	00 00                	add    BYTE PTR [rax],al
 397:	00 00                	add    BYTE PTR [rax],al
 399:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .gnu.hash:

00000000000003a0 <.gnu.hash>:
 3a0:	03 00                	add    eax,DWORD PTR [rax]
 3a2:	00 00                	add    BYTE PTR [rax],al
 3a4:	0e                   	(bad)  
 3a5:	00 00                	add    BYTE PTR [rax],al
 3a7:	00 01                	add    BYTE PTR [rcx],al
 3a9:	00 00                	add    BYTE PTR [rax],al
 3ab:	00 06                	add    BYTE PTR [rsi],al
 3ad:	00 00                	add    BYTE PTR [rax],al
 3af:	00 00                	add    BYTE PTR [rax],al
 3b1:	00 a1 00 80 01 10    	add    BYTE PTR [rcx+0x10018000],ah
 3b7:	00 0e                	add    BYTE PTR [rsi],cl
 3b9:	00 00                	add    BYTE PTR [rax],al
 3bb:	00 10                	add    BYTE PTR [rax],dl
 3bd:	00 00                	add    BYTE PTR [rax],al
 3bf:	00 00                	add    BYTE PTR [rax],al
 3c1:	00 00                	add    BYTE PTR [rax],al
 3c3:	00 28                	add    BYTE PTR [rax],ch
 3c5:	1d 8c 1c d1 65       	sbb    eax,0x65d11c8c
 3ca:	ce                   	(bad)  
 3cb:	6d                   	ins    DWORD PTR es:[rdi],dx
 3cc:	67 55                	addr32 push rbp
 3ce:	61                   	(bad)  
 3cf:	10                   	.byte 0x10

Disassembly of section .dynsym:

00000000000003d0 <.dynsym>:
	...
 3e8:	78 00                	js     3ea <_init-0xc16>
 3ea:	00 00                	add    BYTE PTR [rax],al
 3ec:	20 00                	and    BYTE PTR [rax],al
	...
 3fe:	00 00                	add    BYTE PTR [rax],al
 400:	11 00                	adc    DWORD PTR [rax],eax
 402:	00 00                	add    BYTE PTR [rax],al
 404:	12 00                	adc    al,BYTE PTR [rax]
	...
 416:	00 00                	add    BYTE PTR [rax],al
 418:	21 00                	and    DWORD PTR [rax],eax
 41a:	00 00                	add    BYTE PTR [rax],al
 41c:	12 00                	adc    al,BYTE PTR [rax]
	...
 42e:	00 00                	add    BYTE PTR [rax],al
 430:	28 00                	sub    BYTE PTR [rax],al
 432:	00 00                	add    BYTE PTR [rax],al
 434:	12 00                	adc    al,BYTE PTR [rax]
	...
 446:	00 00                	add    BYTE PTR [rax],al
 448:	5a                   	pop    rdx
 449:	00 00                	add    BYTE PTR [rax],al
 44b:	00 12                	add    BYTE PTR [rdx],dl
	...
 45d:	00 00                	add    BYTE PTR [rax],al
 45f:	00 0b                	add    BYTE PTR [rbx],cl
 461:	00 00                	add    BYTE PTR [rax],al
 463:	00 12                	add    BYTE PTR [rdx],dl
	...
 475:	00 00                	add    BYTE PTR [rax],al
 477:	00 36                	add    BYTE PTR [rsi],dh
 479:	00 00                	add    BYTE PTR [rax],al
 47b:	00 12                	add    BYTE PTR [rdx],dl
	...
 48d:	00 00                	add    BYTE PTR [rax],al
 48f:	00 94 00 00 00 20 00 	add    BYTE PTR [rax+rax*1+0x200000],dl
	...
 4a6:	00 00                	add    BYTE PTR [rax],al
 4a8:	2f                   	(bad)  
 4a9:	00 00                	add    BYTE PTR [rax],al
 4ab:	00 12                	add    BYTE PTR [rdx],dl
	...
 4bd:	00 00                	add    BYTE PTR [rax],al
 4bf:	00 16                	add    BYTE PTR [rsi],dl
 4c1:	00 00                	add    BYTE PTR [rax],al
 4c3:	00 12                	add    BYTE PTR [rdx],dl
	...
 4d5:	00 00                	add    BYTE PTR [rax],al
 4d7:	00 52 00             	add    BYTE PTR [rdx+0x0],dl
 4da:	00 00                	add    BYTE PTR [rax],al
 4dc:	12 00                	adc    al,BYTE PTR [rax]
	...
 4ee:	00 00                	add    BYTE PTR [rax],al
 4f0:	a3 00 00 00 20 00 00 	movabs ds:0x20000000,eax
 4f7:	00 00 
	...
 505:	00 00                	add    BYTE PTR [rax],al
 507:	00 0c 00             	add    BYTE PTR [rax+rax*1],cl
 50a:	00 00                	add    BYTE PTR [rax],al
 50c:	12 00                	adc    al,BYTE PTR [rax]
	...
 51e:	00 00                	add    BYTE PTR [rax],al
 520:	3c 00                	cmp    al,0x0
 522:	00 00                	add    BYTE PTR [rax],al
 524:	11 00                	adc    DWORD PTR [rax],eax
 526:	1a 00                	sbb    al,BYTE PTR [rax]
 528:	10 40 00             	adc    BYTE PTR [rax+0x0],al
 52b:	00 00                	add    BYTE PTR [rax],al
 52d:	00 00                	add    BYTE PTR [rax],al
 52f:	00 08                	add    BYTE PTR [rax],cl
 531:	00 00                	add    BYTE PTR [rax],al
 533:	00 00                	add    BYTE PTR [rax],al
 535:	00 00                	add    BYTE PTR [rax],al
 537:	00 43 00             	add    BYTE PTR [rbx+0x0],al
 53a:	00 00                	add    BYTE PTR [rax],al
 53c:	22 00                	and    al,BYTE PTR [rax]
	...
 54e:	00 00                	add    BYTE PTR [rax],al
 550:	1b 00                	sbb    eax,DWORD PTR [rax]
 552:	00 00                	add    BYTE PTR [rax],al
 554:	11 00                	adc    DWORD PTR [rax],eax
 556:	1a 00                	sbb    al,BYTE PTR [rax]
 558:	20 40 00             	and    BYTE PTR [rax+0x0],al
 55b:	00 00                	add    BYTE PTR [rax],al
 55d:	00 00                	add    BYTE PTR [rax],al
 55f:	00 08                	add    BYTE PTR [rax],cl
 561:	00 00                	add    BYTE PTR [rax],al
 563:	00 00                	add    BYTE PTR [rax],al
 565:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .dynstr:

0000000000000568 <.dynstr>:
 568:	00 6c 69 62          	add    BYTE PTR [rcx+rbp*2+0x62],ch
 56c:	63 2e                	movsxd ebp,DWORD PTR [rsi]
 56e:	73 6f                	jae    5df <_init-0xa21>
 570:	2e 36 00 73 72       	cs add BYTE PTR ss:[rbx+0x72],dh
 575:	61                   	(bad)  
 576:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 577:	64 00 70 75          	add    BYTE PTR fs:[rax+0x75],dh
 57b:	74 73                	je     5f0 <_init-0xa10>
 57d:	00 74 69 6d          	add    BYTE PTR [rcx+rbp*2+0x6d],dh
 581:	65 00 73 74          	add    BYTE PTR gs:[rbx+0x74],dh
 585:	64 69 6e 00 67 65 74 	imul   ebp,DWORD PTR fs:[rsi+0x0],0x70746567
 58c:	70 
 58d:	69 64 00 70 72 69 6e 	imul   esp,DWORD PTR [rax+rax*1+0x70],0x746e6972
 594:	74 
 595:	66 00 73 74          	data16 add BYTE PTR [rbx+0x74],dh
 599:	72 74                	jb     60f <_init-0x9f1>
 59b:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 59c:	6c                   	ins    BYTE PTR es:[rdi],dx
 59d:	00 66 67             	add    BYTE PTR [rsi+0x67],ah
 5a0:	65 74 73             	gs je  616 <_init-0x9ea>
 5a3:	00 73 74             	add    BYTE PTR [rbx+0x74],dh
 5a6:	64 6f                	outs   dx,DWORD PTR fs:[rsi]
 5a8:	75 74                	jne    61e <_init-0x9e2>
 5aa:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
 5ad:	63 78 61             	movsxd edi,DWORD PTR [rax+0x61]
 5b0:	5f                   	pop    rdi
 5b1:	66 69 6e 61 6c 69    	imul   bp,WORD PTR [rsi+0x61],0x696c
 5b7:	7a 65                	jp     61e <_init-0x9e2>
 5b9:	00 73 65             	add    BYTE PTR [rbx+0x65],dh
 5bc:	74 76                	je     634 <_init-0x9cc>
 5be:	62                   	(bad)  
 5bf:	75 66                	jne    627 <_init-0x9d9>
 5c1:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
 5c4:	6c                   	ins    BYTE PTR es:[rdi],dx
 5c5:	69 62 63 5f 73 74 61 	imul   esp,DWORD PTR [rdx+0x63],0x6174735f
 5cc:	72 74                	jb     642 <_init-0x9be>
 5ce:	5f                   	pop    rdi
 5cf:	6d                   	ins    DWORD PTR es:[rdi],dx
 5d0:	61                   	(bad)  
 5d1:	69 6e 00 47 4c 49 42 	imul   ebp,DWORD PTR [rsi+0x0],0x42494c47
 5d8:	43 5f                	rex.XB pop r15
 5da:	32 2e                	xor    ch,BYTE PTR [rsi]
 5dc:	32 2e                	xor    ch,BYTE PTR [rsi]
 5de:	35 00 5f 49 54       	xor    eax,0x54495f00
 5e3:	4d 5f                	rex.WRB pop r15
 5e5:	64 65 72 65          	fs gs jb 64e <_init-0x9b2>
 5e9:	67 69 73 74 65 72 54 	imul   esi,DWORD PTR [ebx+0x74],0x4d547265
 5f0:	4d 
 5f1:	43 6c                	rex.XB ins BYTE PTR es:[rdi],dx
 5f3:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 5f4:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 5f5:	65 54                	gs push rsp
 5f7:	61                   	(bad)  
 5f8:	62                   	(bad)  
 5f9:	6c                   	ins    BYTE PTR es:[rdi],dx
 5fa:	65 00 5f 5f          	add    BYTE PTR gs:[rdi+0x5f],bl
 5fe:	67 6d                	ins    DWORD PTR es:[edi],dx
 600:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 601:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 602:	5f                   	pop    rdi
 603:	73 74                	jae    679 <_init-0x987>
 605:	61                   	(bad)  
 606:	72 74                	jb     67c <_init-0x984>
 608:	5f                   	pop    rdi
 609:	5f                   	pop    rdi
 60a:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
 60d:	54                   	push   rsp
 60e:	4d 5f                	rex.WRB pop r15
 610:	72 65                	jb     677 <_init-0x989>
 612:	67 69 73 74 65 72 54 	imul   esi,DWORD PTR [ebx+0x74],0x4d547265
 619:	4d 
 61a:	43 6c                	rex.XB ins BYTE PTR es:[rdi],dx
 61c:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 61d:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 61e:	65 54                	gs push rsp
 620:	61                   	(bad)  
 621:	62                   	.byte 0x62
 622:	6c                   	ins    BYTE PTR es:[rdi],dx
 623:	65                   	gs
	...

Disassembly of section .gnu.version:

0000000000000626 <.gnu.version>:
 626:	00 00                	add    BYTE PTR [rax],al
 628:	00 00                	add    BYTE PTR [rax],al
 62a:	02 00                	add    al,BYTE PTR [rax]
 62c:	02 00                	add    al,BYTE PTR [rax]
 62e:	02 00                	add    al,BYTE PTR [rax]
 630:	02 00                	add    al,BYTE PTR [rax]
 632:	02 00                	add    al,BYTE PTR [rax]
 634:	02 00                	add    al,BYTE PTR [rax]
 636:	00 00                	add    BYTE PTR [rax],al
 638:	02 00                	add    al,BYTE PTR [rax]
 63a:	02 00                	add    al,BYTE PTR [rax]
 63c:	02 00                	add    al,BYTE PTR [rax]
 63e:	00 00                	add    BYTE PTR [rax],al
 640:	02 00                	add    al,BYTE PTR [rax]
 642:	02 00                	add    al,BYTE PTR [rax]
 644:	02 00                	add    al,BYTE PTR [rax]
 646:	02 00                	add    al,BYTE PTR [rax]

Disassembly of section .gnu.version_r:

0000000000000648 <.gnu.version_r>:
 648:	01 00                	add    DWORD PTR [rax],eax
 64a:	01 00                	add    DWORD PTR [rax],eax
 64c:	01 00                	add    DWORD PTR [rax],eax
 64e:	00 00                	add    BYTE PTR [rax],al
 650:	10 00                	adc    BYTE PTR [rax],al
 652:	00 00                	add    BYTE PTR [rax],al
 654:	00 00                	add    BYTE PTR [rax],al
 656:	00 00                	add    BYTE PTR [rax],al
 658:	75 1a                	jne    674 <_init-0x98c>
 65a:	69 09 00 00 02 00    	imul   ecx,DWORD PTR [rcx],0x20000
 660:	6c                   	ins    BYTE PTR es:[rdi],dx
 661:	00 00                	add    BYTE PTR [rax],al
 663:	00 00                	add    BYTE PTR [rax],al
 665:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .rela.dyn:

0000000000000668 <.rela.dyn>:
 668:	78 3d                	js     6a7 <_init-0x959>
 66a:	00 00                	add    BYTE PTR [rax],al
 66c:	00 00                	add    BYTE PTR [rax],al
 66e:	00 00                	add    BYTE PTR [rax],al
 670:	08 00                	or     BYTE PTR [rax],al
 672:	00 00                	add    BYTE PTR [rax],al
 674:	00 00                	add    BYTE PTR [rax],al
 676:	00 00                	add    BYTE PTR [rax],al
 678:	40 12 00             	adc    al,BYTE PTR [rax]
 67b:	00 00                	add    BYTE PTR [rax],al
 67d:	00 00                	add    BYTE PTR [rax],al
 67f:	00 80 3d 00 00 00    	add    BYTE PTR [rax+0x3d],al
 685:	00 00                	add    BYTE PTR [rax],al
 687:	00 08                	add    BYTE PTR [rax],cl
	...
 691:	12 00                	adc    al,BYTE PTR [rax]
 693:	00 00                	add    BYTE PTR [rax],al
 695:	00 00                	add    BYTE PTR [rax],al
 697:	00 08                	add    BYTE PTR [rax],cl
 699:	40 00 00             	add    BYTE PTR [rax],al
 69c:	00 00                	add    BYTE PTR [rax],al
 69e:	00 00                	add    BYTE PTR [rax],al
 6a0:	08 00                	or     BYTE PTR [rax],al
 6a2:	00 00                	add    BYTE PTR [rax],al
 6a4:	00 00                	add    BYTE PTR [rax],al
 6a6:	00 00                	add    BYTE PTR [rax],al
 6a8:	08 40 00             	or     BYTE PTR [rax+0x0],al
 6ab:	00 00                	add    BYTE PTR [rax],al
 6ad:	00 00                	add    BYTE PTR [rax],al
 6af:	00 d8                	add    al,bl
 6b1:	3f                   	(bad)  
 6b2:	00 00                	add    BYTE PTR [rax],al
 6b4:	00 00                	add    BYTE PTR [rax],al
 6b6:	00 00                	add    BYTE PTR [rax],al
 6b8:	06                   	(bad)  
 6b9:	00 00                	add    BYTE PTR [rax],al
 6bb:	00 01                	add    BYTE PTR [rcx],al
	...
 6c5:	00 00                	add    BYTE PTR [rax],al
 6c7:	00 e0                	add    al,ah
 6c9:	3f                   	(bad)  
 6ca:	00 00                	add    BYTE PTR [rax],al
 6cc:	00 00                	add    BYTE PTR [rax],al
 6ce:	00 00                	add    BYTE PTR [rax],al
 6d0:	06                   	(bad)  
 6d1:	00 00                	add    BYTE PTR [rax],al
 6d3:	00 05 00 00 00 00    	add    BYTE PTR [rip+0x0],al        # 6d9 <_init-0x927>
 6d9:	00 00                	add    BYTE PTR [rax],al
 6db:	00 00                	add    BYTE PTR [rax],al
 6dd:	00 00                	add    BYTE PTR [rax],al
 6df:	00 e8                	add    al,ch
 6e1:	3f                   	(bad)  
 6e2:	00 00                	add    BYTE PTR [rax],al
 6e4:	00 00                	add    BYTE PTR [rax],al
 6e6:	00 00                	add    BYTE PTR [rax],al
 6e8:	06                   	(bad)  
 6e9:	00 00                	add    BYTE PTR [rax],al
 6eb:	00 08                	add    BYTE PTR [rax],cl
	...
 6f5:	00 00                	add    BYTE PTR [rax],al
 6f7:	00 f0                	add    al,dh
 6f9:	3f                   	(bad)  
 6fa:	00 00                	add    BYTE PTR [rax],al
 6fc:	00 00                	add    BYTE PTR [rax],al
 6fe:	00 00                	add    BYTE PTR [rax],al
 700:	06                   	(bad)  
 701:	00 00                	add    BYTE PTR [rax],al
 703:	00 0c 00             	add    BYTE PTR [rax+rax*1],cl
	...
 70e:	00 00                	add    BYTE PTR [rax],al
 710:	f8                   	clc    
 711:	3f                   	(bad)  
 712:	00 00                	add    BYTE PTR [rax],al
 714:	00 00                	add    BYTE PTR [rax],al
 716:	00 00                	add    BYTE PTR [rax],al
 718:	06                   	(bad)  
 719:	00 00                	add    BYTE PTR [rax],al
 71b:	00 0f                	add    BYTE PTR [rdi],cl
	...
 725:	00 00                	add    BYTE PTR [rax],al
 727:	00 10                	add    BYTE PTR [rax],dl
 729:	40 00 00             	add    BYTE PTR [rax],al
 72c:	00 00                	add    BYTE PTR [rax],al
 72e:	00 00                	add    BYTE PTR [rax],al
 730:	05 00 00 00 0e       	add    eax,0xe000000
	...
 73d:	00 00                	add    BYTE PTR [rax],al
 73f:	00 20                	add    BYTE PTR [rax],ah
 741:	40 00 00             	add    BYTE PTR [rax],al
 744:	00 00                	add    BYTE PTR [rax],al
 746:	00 00                	add    BYTE PTR [rax],al
 748:	05 00 00 00 10       	add    eax,0x10000000
	...

Disassembly of section .rela.plt:

0000000000000758 <.rela.plt>:
 758:	90                   	nop
 759:	3f                   	(bad)  
 75a:	00 00                	add    BYTE PTR [rax],al
 75c:	00 00                	add    BYTE PTR [rax],al
 75e:	00 00                	add    BYTE PTR [rax],al
 760:	07                   	(bad)  
 761:	00 00                	add    BYTE PTR [rax],al
 763:	00 02                	add    BYTE PTR [rdx],al
	...
 76d:	00 00                	add    BYTE PTR [rax],al
 76f:	00 98 3f 00 00 00    	add    BYTE PTR [rax+0x3f],bl
 775:	00 00                	add    BYTE PTR [rax],al
 777:	00 07                	add    BYTE PTR [rdi],al
 779:	00 00                	add    BYTE PTR [rax],al
 77b:	00 03                	add    BYTE PTR [rbx],al
	...
 785:	00 00                	add    BYTE PTR [rax],al
 787:	00 a0 3f 00 00 00    	add    BYTE PTR [rax+0x3f],ah
 78d:	00 00                	add    BYTE PTR [rax],al
 78f:	00 07                	add    BYTE PTR [rdi],al
 791:	00 00                	add    BYTE PTR [rax],al
 793:	00 04 00             	add    BYTE PTR [rax+rax*1],al
	...
 79e:	00 00                	add    BYTE PTR [rax],al
 7a0:	a8 3f                	test   al,0x3f
 7a2:	00 00                	add    BYTE PTR [rax],al
 7a4:	00 00                	add    BYTE PTR [rax],al
 7a6:	00 00                	add    BYTE PTR [rax],al
 7a8:	07                   	(bad)  
 7a9:	00 00                	add    BYTE PTR [rax],al
 7ab:	00 06                	add    BYTE PTR [rsi],al
	...
 7b5:	00 00                	add    BYTE PTR [rax],al
 7b7:	00 b0 3f 00 00 00    	add    BYTE PTR [rax+0x3f],dh
 7bd:	00 00                	add    BYTE PTR [rax],al
 7bf:	00 07                	add    BYTE PTR [rdi],al
 7c1:	00 00                	add    BYTE PTR [rax],al
 7c3:	00 07                	add    BYTE PTR [rdi],al
	...
 7cd:	00 00                	add    BYTE PTR [rax],al
 7cf:	00 b8 3f 00 00 00    	add    BYTE PTR [rax+0x3f],bh
 7d5:	00 00                	add    BYTE PTR [rax],al
 7d7:	00 07                	add    BYTE PTR [rdi],al
 7d9:	00 00                	add    BYTE PTR [rax],al
 7db:	00 09                	add    BYTE PTR [rcx],cl
	...
 7e5:	00 00                	add    BYTE PTR [rax],al
 7e7:	00 c0                	add    al,al
 7e9:	3f                   	(bad)  
 7ea:	00 00                	add    BYTE PTR [rax],al
 7ec:	00 00                	add    BYTE PTR [rax],al
 7ee:	00 00                	add    BYTE PTR [rax],al
 7f0:	07                   	(bad)  
 7f1:	00 00                	add    BYTE PTR [rax],al
 7f3:	00 0a                	add    BYTE PTR [rdx],cl
	...
 7fd:	00 00                	add    BYTE PTR [rax],al
 7ff:	00 c8                	add    al,cl
 801:	3f                   	(bad)  
 802:	00 00                	add    BYTE PTR [rax],al
 804:	00 00                	add    BYTE PTR [rax],al
 806:	00 00                	add    BYTE PTR [rax],al
 808:	07                   	(bad)  
 809:	00 00                	add    BYTE PTR [rax],al
 80b:	00 0b                	add    BYTE PTR [rbx],cl
	...
 815:	00 00                	add    BYTE PTR [rax],al
 817:	00 d0                	add    al,dl
 819:	3f                   	(bad)  
 81a:	00 00                	add    BYTE PTR [rax],al
 81c:	00 00                	add    BYTE PTR [rax],al
 81e:	00 00                	add    BYTE PTR [rax],al
 820:	07                   	(bad)  
 821:	00 00                	add    BYTE PTR [rax],al
 823:	00 0d 00 00 00 00    	add    BYTE PTR [rip+0x0],cl        # 829 <_init-0x7d7>
 829:	00 00                	add    BYTE PTR [rax],al
 82b:	00 00                	add    BYTE PTR [rax],al
 82d:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    rsp,0x8
    1008:	48 8b 05 d9 2f 00 00 	mov    rax,QWORD PTR [rip+0x2fd9]        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   rax,rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   rax
    1016:	48 83 c4 08          	add    rsp,0x8
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 5a 2f 00 00    	push   QWORD PTR [rip+0x2f5a]        # 3f80 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 5b 2f 00 00 	bnd jmp QWORD PTR [rip+0x2f5b]        # 3f88 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nop    DWORD PTR [rax]
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	push   0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmp 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	push   0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmp 1020 <.plt>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	push   0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmp 1020 <.plt>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	push   0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmp 1020 <.plt>
    106f:	90                   	nop
    1070:	f3 0f 1e fa          	endbr64 
    1074:	68 04 00 00 00       	push   0x4
    1079:	f2 e9 a1 ff ff ff    	bnd jmp 1020 <.plt>
    107f:	90                   	nop
    1080:	f3 0f 1e fa          	endbr64 
    1084:	68 05 00 00 00       	push   0x5
    1089:	f2 e9 91 ff ff ff    	bnd jmp 1020 <.plt>
    108f:	90                   	nop
    1090:	f3 0f 1e fa          	endbr64 
    1094:	68 06 00 00 00       	push   0x6
    1099:	f2 e9 81 ff ff ff    	bnd jmp 1020 <.plt>
    109f:	90                   	nop
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	68 07 00 00 00       	push   0x7
    10a9:	f2 e9 71 ff ff ff    	bnd jmp 1020 <.plt>
    10af:	90                   	nop
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	68 08 00 00 00       	push   0x8
    10b9:	f2 e9 61 ff ff ff    	bnd jmp 1020 <.plt>
    10bf:	90                   	nop

Disassembly of section .plt.got:

00000000000010c0 <__cxa_finalize@plt>:
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	f2 ff 25 2d 2f 00 00 	bnd jmp QWORD PTR [rip+0x2f2d]        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    10cb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

Disassembly of section .plt.sec:

00000000000010d0 <puts@plt>:
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	f2 ff 25 b5 2e 00 00 	bnd jmp QWORD PTR [rip+0x2eb5]        # 3f90 <puts@GLIBC_2.2.5>
    10db:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000010e0 <getpid@plt>:
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	f2 ff 25 ad 2e 00 00 	bnd jmp QWORD PTR [rip+0x2ead]        # 3f98 <getpid@GLIBC_2.2.5>
    10eb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000010f0 <printf@plt>:
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	f2 ff 25 a5 2e 00 00 	bnd jmp QWORD PTR [rip+0x2ea5]        # 3fa0 <printf@GLIBC_2.2.5>
    10fb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000001100 <srand@plt>:
    1100:	f3 0f 1e fa          	endbr64 
    1104:	f2 ff 25 9d 2e 00 00 	bnd jmp QWORD PTR [rip+0x2e9d]        # 3fa8 <srand@GLIBC_2.2.5>
    110b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000001110 <fgets@plt>:
    1110:	f3 0f 1e fa          	endbr64 
    1114:	f2 ff 25 95 2e 00 00 	bnd jmp QWORD PTR [rip+0x2e95]        # 3fb0 <fgets@GLIBC_2.2.5>
    111b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000001120 <strtol@plt>:
    1120:	f3 0f 1e fa          	endbr64 
    1124:	f2 ff 25 8d 2e 00 00 	bnd jmp QWORD PTR [rip+0x2e8d]        # 3fb8 <strtol@GLIBC_2.2.5>
    112b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000001130 <time@plt>:
    1130:	f3 0f 1e fa          	endbr64 
    1134:	f2 ff 25 85 2e 00 00 	bnd jmp QWORD PTR [rip+0x2e85]        # 3fc0 <time@GLIBC_2.2.5>
    113b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000001140 <setvbuf@plt>:
    1140:	f3 0f 1e fa          	endbr64 
    1144:	f2 ff 25 7d 2e 00 00 	bnd jmp QWORD PTR [rip+0x2e7d]        # 3fc8 <setvbuf@GLIBC_2.2.5>
    114b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000001150 <rand@plt>:
    1150:	f3 0f 1e fa          	endbr64 
    1154:	f2 ff 25 75 2e 00 00 	bnd jmp QWORD PTR [rip+0x2e75]        # 3fd0 <rand@GLIBC_2.2.5>
    115b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

Disassembly of section .text:

0000000000001160 <_start>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	31 ed                	xor    ebp,ebp
    1166:	49 89 d1             	mov    r9,rdx
    1169:	5e                   	pop    rsi
    116a:	48 89 e2             	mov    rdx,rsp
    116d:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
    1171:	50                   	push   rax
    1172:	54                   	push   rsp
    1173:	4c 8d 05 46 02 00 00 	lea    r8,[rip+0x246]        # 13c0 <__libc_csu_fini>
    117a:	48 8d 0d cf 01 00 00 	lea    rcx,[rip+0x1cf]        # 1350 <__libc_csu_init>
    1181:	48 8d 3d c1 00 00 00 	lea    rdi,[rip+0xc1]        # 1249 <main>
    1188:	ff 15 52 2e 00 00    	call   QWORD PTR [rip+0x2e52]        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    118e:	f4                   	hlt    
    118f:	90                   	nop

0000000000001190 <deregister_tm_clones>:
    1190:	48 8d 3d 79 2e 00 00 	lea    rdi,[rip+0x2e79]        # 4010 <stdout@@GLIBC_2.2.5>
    1197:	48 8d 05 72 2e 00 00 	lea    rax,[rip+0x2e72]        # 4010 <stdout@@GLIBC_2.2.5>
    119e:	48 39 f8             	cmp    rax,rdi
    11a1:	74 15                	je     11b8 <deregister_tm_clones+0x28>
    11a3:	48 8b 05 2e 2e 00 00 	mov    rax,QWORD PTR [rip+0x2e2e]        # 3fd8 <_ITM_deregisterTMCloneTable>
    11aa:	48 85 c0             	test   rax,rax
    11ad:	74 09                	je     11b8 <deregister_tm_clones+0x28>
    11af:	ff e0                	jmp    rax
    11b1:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    11b8:	c3                   	ret    
    11b9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000011c0 <register_tm_clones>:
    11c0:	48 8d 3d 49 2e 00 00 	lea    rdi,[rip+0x2e49]        # 4010 <stdout@@GLIBC_2.2.5>
    11c7:	48 8d 35 42 2e 00 00 	lea    rsi,[rip+0x2e42]        # 4010 <stdout@@GLIBC_2.2.5>
    11ce:	48 29 fe             	sub    rsi,rdi
    11d1:	48 89 f0             	mov    rax,rsi
    11d4:	48 c1 ee 3f          	shr    rsi,0x3f
    11d8:	48 c1 f8 03          	sar    rax,0x3
    11dc:	48 01 c6             	add    rsi,rax
    11df:	48 d1 fe             	sar    rsi,1
    11e2:	74 14                	je     11f8 <register_tm_clones+0x38>
    11e4:	48 8b 05 05 2e 00 00 	mov    rax,QWORD PTR [rip+0x2e05]        # 3ff0 <_ITM_registerTMCloneTable>
    11eb:	48 85 c0             	test   rax,rax
    11ee:	74 08                	je     11f8 <register_tm_clones+0x38>
    11f0:	ff e0                	jmp    rax
    11f2:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    11f8:	c3                   	ret    
    11f9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001200 <__do_global_dtors_aux>:
    1200:	f3 0f 1e fa          	endbr64 
    1204:	80 3d 1d 2e 00 00 00 	cmp    BYTE PTR [rip+0x2e1d],0x0        # 4028 <completed.8061>
    120b:	75 2b                	jne    1238 <__do_global_dtors_aux+0x38>
    120d:	55                   	push   rbp
    120e:	48 83 3d e2 2d 00 00 	cmp    QWORD PTR [rip+0x2de2],0x0        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1215:	00 
    1216:	48 89 e5             	mov    rbp,rsp
    1219:	74 0c                	je     1227 <__do_global_dtors_aux+0x27>
    121b:	48 8b 3d e6 2d 00 00 	mov    rdi,QWORD PTR [rip+0x2de6]        # 4008 <__dso_handle>
    1222:	e8 99 fe ff ff       	call   10c0 <__cxa_finalize@plt>
    1227:	e8 64 ff ff ff       	call   1190 <deregister_tm_clones>
    122c:	c6 05 f5 2d 00 00 01 	mov    BYTE PTR [rip+0x2df5],0x1        # 4028 <completed.8061>
    1233:	5d                   	pop    rbp
    1234:	c3                   	ret    
    1235:	0f 1f 00             	nop    DWORD PTR [rax]
    1238:	c3                   	ret    
    1239:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001240 <frame_dummy>:
    1240:	f3 0f 1e fa          	endbr64 
    1244:	e9 77 ff ff ff       	jmp    11c0 <register_tm_clones>

0000000000001249 <main>:
    1249:	f3 0f 1e fa          	endbr64 
    124d:	55                   	push   rbp
    124e:	48 89 e5             	mov    rbp,rsp
    1251:	53                   	push   rbx
    1252:	48 83 ec 28          	sub    rsp,0x28
    1256:	48 8b 05 b3 2d 00 00 	mov    rax,QWORD PTR [rip+0x2db3]        # 4010 <stdout@@GLIBC_2.2.5>
    125d:	b9 00 00 00 00       	mov    ecx,0x0
    1262:	ba 02 00 00 00       	mov    edx,0x2
    1267:	be 00 00 00 00       	mov    esi,0x0
    126c:	48 89 c7             	mov    rdi,rax
    126f:	e8 cc fe ff ff       	call   1140 <setvbuf@plt>
    1274:	bf 00 00 00 00       	mov    edi,0x0
    1279:	e8 b2 fe ff ff       	call   1130 <time@plt>
    127e:	89 c3                	mov    ebx,eax
    1280:	e8 5b fe ff ff       	call   10e0 <getpid@plt>
    1285:	31 d8                	xor    eax,ebx
    1287:	89 c7                	mov    edi,eax
    1289:	e8 72 fe ff ff       	call   1100 <srand@plt>
    128e:	e8 bd fe ff ff       	call   1150 <rand@plt>
    1293:	48 63 d0             	movsxd rdx,eax
    1296:	48 69 d2 ad 8b db 68 	imul   rdx,rdx,0x68db8bad
    129d:	48 c1 ea 20          	shr    rdx,0x20
    12a1:	89 d1                	mov    ecx,edx
    12a3:	c1 f9 0c             	sar    ecx,0xc
    12a6:	99                   	cdq    
    12a7:	29 d1                	sub    ecx,edx
    12a9:	89 ca                	mov    edx,ecx
    12ab:	89 55 ec             	mov    DWORD PTR [rbp-0x14],edx
    12ae:	8b 55 ec             	mov    edx,DWORD PTR [rbp-0x14]
    12b1:	69 d2 10 27 00 00    	imul   edx,edx,0x2710
    12b7:	29 d0                	sub    eax,edx
    12b9:	89 45 ec             	mov    DWORD PTR [rbp-0x14],eax
    12bc:	48 8d 3d 41 0d 00 00 	lea    rdi,[rip+0xd41]        # 2004 <_IO_stdin_used+0x4>
    12c3:	b8 00 00 00 00       	mov    eax,0x0
    12c8:	e8 23 fe ff ff       	call   10f0 <printf@plt>
    12cd:	48 8b 15 4c 2d 00 00 	mov    rdx,QWORD PTR [rip+0x2d4c]        # 4020 <stdin@@GLIBC_2.2.5>
    12d4:	48 8d 45 d0          	lea    rax,[rbp-0x30]
    12d8:	be 20 00 00 00       	mov    esi,0x20
    12dd:	48 89 c7             	mov    rdi,rax
    12e0:	e8 2b fe ff ff       	call   1110 <fgets@plt>
    12e5:	48 85 c0             	test   rax,rax
    12e8:	74 51                	je     133b <main+0xf2>
    12ea:	48 8d 45 d0          	lea    rax,[rbp-0x30]
    12ee:	ba 00 00 00 00       	mov    edx,0x0
    12f3:	be 00 00 00 00       	mov    esi,0x0
    12f8:	48 89 c7             	mov    rdi,rax
    12fb:	e8 20 fe ff ff       	call   1120 <strtol@plt>
    1300:	89 45 e8             	mov    DWORD PTR [rbp-0x18],eax
    1303:	8b 45 e8             	mov    eax,DWORD PTR [rbp-0x18]
    1306:	89 c6                	mov    esi,eax
    1308:	48 8d 3d 08 0d 00 00 	lea    rdi,[rip+0xd08]        # 2017 <_IO_stdin_used+0x17>
    130f:	b8 00 00 00 00       	mov    eax,0x0
    1314:	e8 d7 fd ff ff       	call   10f0 <printf@plt>
    1319:	8b 45 e8             	mov    eax,DWORD PTR [rbp-0x18]
    131c:	3b 45 ec             	cmp    eax,DWORD PTR [rbp-0x14]
    131f:	75 0e                	jne    132f <main+0xe6>
    1321:	48 8d 3d 01 0d 00 00 	lea    rdi,[rip+0xd01]        # 2029 <_IO_stdin_used+0x29>
    1328:	e8 a3 fd ff ff       	call   10d0 <puts@plt>
    132d:	eb 0c                	jmp    133b <main+0xf2>
    132f:	48 8d 3d fa 0c 00 00 	lea    rdi,[rip+0xcfa]        # 2030 <_IO_stdin_used+0x30>
    1336:	e8 95 fd ff ff       	call   10d0 <puts@plt>
    133b:	b8 00 00 00 00       	mov    eax,0x0
    1340:	48 83 c4 28          	add    rsp,0x28
    1344:	5b                   	pop    rbx
    1345:	5d                   	pop    rbp
    1346:	c3                   	ret    
    1347:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    134e:	00 00 

0000000000001350 <__libc_csu_init>:
    1350:	f3 0f 1e fa          	endbr64 
    1354:	41 57                	push   r15
    1356:	4c 8d 3d 1b 2a 00 00 	lea    r15,[rip+0x2a1b]        # 3d78 <__frame_dummy_init_array_entry>
    135d:	41 56                	push   r14
    135f:	49 89 d6             	mov    r14,rdx
    1362:	41 55                	push   r13
    1364:	49 89 f5             	mov    r13,rsi
    1367:	41 54                	push   r12
    1369:	41 89 fc             	mov    r12d,edi
    136c:	55                   	push   rbp
    136d:	48 8d 2d 0c 2a 00 00 	lea    rbp,[rip+0x2a0c]        # 3d80 <__do_global_dtors_aux_fini_array_entry>
    1374:	53                   	push   rbx
    1375:	4c 29 fd             	sub    rbp,r15
    1378:	48 83 ec 08          	sub    rsp,0x8
    137c:	e8 7f fc ff ff       	call   1000 <_init>
    1381:	48 c1 fd 03          	sar    rbp,0x3
    1385:	74 1f                	je     13a6 <__libc_csu_init+0x56>
    1387:	31 db                	xor    ebx,ebx
    1389:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1390:	4c 89 f2             	mov    rdx,r14
    1393:	4c 89 ee             	mov    rsi,r13
    1396:	44 89 e7             	mov    edi,r12d
    1399:	41 ff 14 df          	call   QWORD PTR [r15+rbx*8]
    139d:	48 83 c3 01          	add    rbx,0x1
    13a1:	48 39 dd             	cmp    rbp,rbx
    13a4:	75 ea                	jne    1390 <__libc_csu_init+0x40>
    13a6:	48 83 c4 08          	add    rsp,0x8
    13aa:	5b                   	pop    rbx
    13ab:	5d                   	pop    rbp
    13ac:	41 5c                	pop    r12
    13ae:	41 5d                	pop    r13
    13b0:	41 5e                	pop    r14
    13b2:	41 5f                	pop    r15
    13b4:	c3                   	ret    
    13b5:	66 66 2e 0f 1f 84 00 	data16 nop WORD PTR cs:[rax+rax*1+0x0]
    13bc:	00 00 00 00 

00000000000013c0 <__libc_csu_fini>:
    13c0:	f3 0f 1e fa          	endbr64 
    13c4:	c3                   	ret    

Disassembly of section .fini:

00000000000013c8 <_fini>:
    13c8:	f3 0f 1e fa          	endbr64 
    13cc:	48 83 ec 08          	sub    rsp,0x8
    13d0:	48 83 c4 08          	add    rsp,0x8
    13d4:	c3                   	ret    

Disassembly of section .rodata:

0000000000002000 <_IO_stdin_used>:
    2000:	01 00                	add    DWORD PTR [rax],eax
    2002:	02 00                	add    al,BYTE PTR [rax]
    2004:	47 75 65             	rex.RXB jne 206c <__GNU_EH_FRAME_HDR+0x2c>
    2007:	73 73                	jae    207c <__GNU_EH_FRAME_HDR+0x3c>
    2009:	20 74 68 65          	and    BYTE PTR [rax+rbp*2+0x65],dh
    200d:	20 6e 75             	and    BYTE PTR [rsi+0x75],ch
    2010:	6d                   	ins    DWORD PTR es:[rdi],dx
    2011:	62                   	(bad)  
    2012:	65 72 3a             	gs jb  204f <__GNU_EH_FRAME_HDR+0xf>
    2015:	20 00                	and    BYTE PTR [rax],al
    2017:	59                   	pop    rcx
    2018:	6f                   	outs   dx,DWORD PTR ds:[rsi]
    2019:	75 72                	jne    208d <__GNU_EH_FRAME_HDR+0x4d>
    201b:	20 67 75             	and    BYTE PTR [rdi+0x75],ah
    201e:	65 73 73             	gs jae 2094 <__GNU_EH_FRAME_HDR+0x54>
    2021:	20 69 73             	and    BYTE PTR [rcx+0x73],ch
    2024:	20 25 64 0a 00 42    	and    BYTE PTR [rip+0x42000a64],ah        # 42002a8e <_end+0x41ffea5e>
    202a:	69 6e 67 6f 21 00 4e 	imul   ebp,DWORD PTR [rsi+0x67],0x4e00216f
    2031:	6f                   	outs   dx,DWORD PTR ds:[rsi]
    2032:	20 6e 6f             	and    BYTE PTR [rsi+0x6f],ch
    2035:	20 6e 6f             	and    BYTE PTR [rsi+0x6f],ch
    2038:	20 2e                	and    BYTE PTR [rsi],ch
    203a:	2e                   	cs
    203b:	2e                   	cs
	...

Disassembly of section .eh_frame_hdr:

0000000000002040 <__GNU_EH_FRAME_HDR>:
    2040:	01 1b                	add    DWORD PTR [rbx],ebx
    2042:	03 3b                	add    edi,DWORD PTR [rbx]
    2044:	44 00 00             	add    BYTE PTR [rax],r8b
    2047:	00 07                	add    BYTE PTR [rdi],al
    2049:	00 00                	add    BYTE PTR [rax],al
    204b:	00 e0                	add    al,ah
    204d:	ef                   	out    dx,eax
    204e:	ff                   	(bad)  
    204f:	ff                   	(bad)  
    2050:	78 00                	js     2052 <__GNU_EH_FRAME_HDR+0x12>
    2052:	00 00                	add    BYTE PTR [rax],al
    2054:	80 f0 ff             	xor    al,0xff
    2057:	ff a0 00 00 00 90    	jmp    QWORD PTR [rax-0x70000000]
    205d:	f0 ff                	lock (bad) 
    205f:	ff                   	(bad)  
    2060:	b8 00 00 00 20       	mov    eax,0x20000000
    2065:	f1                   	icebp  
    2066:	ff                   	(bad)  
    2067:	ff 60 00             	jmp    QWORD PTR [rax+0x0]
    206a:	00 00                	add    BYTE PTR [rax],al
    206c:	09 f2                	or     edx,esi
    206e:	ff                   	(bad)  
    206f:	ff d0                	call   rax
    2071:	00 00                	add    BYTE PTR [rax],al
    2073:	00 10                	add    BYTE PTR [rax],dl
    2075:	f3 ff                	repz (bad) 
    2077:	ff                   	(bad)  
    2078:	f8                   	clc    
    2079:	00 00                	add    BYTE PTR [rax],al
    207b:	00 80 f3 ff ff 40    	add    BYTE PTR [rax+0x40fffff3],al
    2081:	01 00                	add    DWORD PTR [rax],eax
	...

Disassembly of section .eh_frame:

0000000000002088 <__FRAME_END__-0x10c>:
    2088:	14 00                	adc    al,0x0
    208a:	00 00                	add    BYTE PTR [rax],al
    208c:	00 00                	add    BYTE PTR [rax],al
    208e:	00 00                	add    BYTE PTR [rax],al
    2090:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
    2093:	00 01                	add    BYTE PTR [rcx],al
    2095:	78 10                	js     20a7 <__GNU_EH_FRAME_HDR+0x67>
    2097:	01 1b                	add    DWORD PTR [rbx],ebx
    2099:	0c 07                	or     al,0x7
    209b:	08 90 01 00 00 14    	or     BYTE PTR [rax+0x14000001],dl
    20a1:	00 00                	add    BYTE PTR [rax],al
    20a3:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
    20a6:	00 00                	add    BYTE PTR [rax],al
    20a8:	b8 f0 ff ff 2f       	mov    eax,0x2ffffff0
    20ad:	00 00                	add    BYTE PTR [rax],al
    20af:	00 00                	add    BYTE PTR [rax],al
    20b1:	44 07                	rex.R (bad) 
    20b3:	10 00                	adc    BYTE PTR [rax],al
    20b5:	00 00                	add    BYTE PTR [rax],al
    20b7:	00 24 00             	add    BYTE PTR [rax+rax*1],ah
    20ba:	00 00                	add    BYTE PTR [rax],al
    20bc:	34 00                	xor    al,0x0
    20be:	00 00                	add    BYTE PTR [rax],al
    20c0:	60                   	(bad)  
    20c1:	ef                   	out    dx,eax
    20c2:	ff                   	(bad)  
    20c3:	ff a0 00 00 00 00    	jmp    QWORD PTR [rax+0x0]
    20c9:	0e                   	(bad)  
    20ca:	10 46 0e             	adc    BYTE PTR [rsi+0xe],al
    20cd:	18 4a 0f             	sbb    BYTE PTR [rdx+0xf],cl
    20d0:	0b 77 08             	or     esi,DWORD PTR [rdi+0x8]
    20d3:	80 00 3f             	add    BYTE PTR [rax],0x3f
    20d6:	1a 3a                	sbb    bh,BYTE PTR [rdx]
    20d8:	2a 33                	sub    dh,BYTE PTR [rbx]
    20da:	24 22                	and    al,0x22
    20dc:	00 00                	add    BYTE PTR [rax],al
    20de:	00 00                	add    BYTE PTR [rax],al
    20e0:	14 00                	adc    al,0x0
    20e2:	00 00                	add    BYTE PTR [rax],al
    20e4:	5c                   	pop    rsp
    20e5:	00 00                	add    BYTE PTR [rax],al
    20e7:	00 d8                	add    al,bl
    20e9:	ef                   	out    dx,eax
    20ea:	ff                   	(bad)  
    20eb:	ff 10                	call   QWORD PTR [rax]
	...
    20f5:	00 00                	add    BYTE PTR [rax],al
    20f7:	00 14 00             	add    BYTE PTR [rax+rax*1],dl
    20fa:	00 00                	add    BYTE PTR [rax],al
    20fc:	74 00                	je     20fe <__GNU_EH_FRAME_HDR+0xbe>
    20fe:	00 00                	add    BYTE PTR [rax],al
    2100:	d0 ef                	shr    bh,1
    2102:	ff                   	(bad)  
    2103:	ff 90 00 00 00 00    	call   QWORD PTR [rax+0x0]
    2109:	00 00                	add    BYTE PTR [rax],al
    210b:	00 00                	add    BYTE PTR [rax],al
    210d:	00 00                	add    BYTE PTR [rax],al
    210f:	00 24 00             	add    BYTE PTR [rax+rax*1],ah
    2112:	00 00                	add    BYTE PTR [rax],al
    2114:	8c 00                	mov    WORD PTR [rax],es
    2116:	00 00                	add    BYTE PTR [rax],al
    2118:	31 f1                	xor    ecx,esi
    211a:	ff                   	(bad)  
    211b:	ff                   	(bad)  
    211c:	fe 00                	inc    BYTE PTR [rax]
    211e:	00 00                	add    BYTE PTR [rax],al
    2120:	00 45 0e             	add    BYTE PTR [rbp+0xe],al
    2123:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
    2129:	45 83 03 02          	rex.RB add DWORD PTR [r11],0x2
    212d:	f0 0c 07             	lock or al,0x7
    2130:	08 00                	or     BYTE PTR [rax],al
    2132:	00 00                	add    BYTE PTR [rax],al
    2134:	00 00                	add    BYTE PTR [rax],al
    2136:	00 00                	add    BYTE PTR [rax],al
    2138:	44 00 00             	add    BYTE PTR [rax],r8b
    213b:	00 b4 00 00 00 10 f2 	add    BYTE PTR [rax+rax*1-0xdf00000],dh
    2142:	ff                   	(bad)  
    2143:	ff 65 00             	jmp    QWORD PTR [rbp+0x0]
    2146:	00 00                	add    BYTE PTR [rax],al
    2148:	00 46 0e             	add    BYTE PTR [rsi+0xe],al
    214b:	10 8f 02 49 0e 18    	adc    BYTE PTR [rdi+0x180e4902],cl
    2151:	8e 03                	mov    es,WORD PTR [rbx]
    2153:	45 0e                	rex.RB (bad) 
    2155:	20 8d 04 45 0e 28    	and    BYTE PTR [rbp+0x280e4504],cl
    215b:	8c 05 44 0e 30 86    	mov    WORD PTR [rip+0xffffffff86300e44],es        # ffffffff86302fa5 <_end+0xffffffff862fef75>
    2161:	06                   	(bad)  
    2162:	48 0e                	rex.W (bad) 
    2164:	38 83 07 47 0e 40    	cmp    BYTE PTR [rbx+0x400e4707],al
    216a:	6e                   	outs   dx,BYTE PTR ds:[rsi]
    216b:	0e                   	(bad)  
    216c:	38 41 0e             	cmp    BYTE PTR [rcx+0xe],al
    216f:	30 41 0e             	xor    BYTE PTR [rcx+0xe],al
    2172:	28 42 0e             	sub    BYTE PTR [rdx+0xe],al
    2175:	20 42 0e             	and    BYTE PTR [rdx+0xe],al
    2178:	18 42 0e             	sbb    BYTE PTR [rdx+0xe],al
    217b:	10 42 0e             	adc    BYTE PTR [rdx+0xe],al
    217e:	08 00                	or     BYTE PTR [rax],al
    2180:	10 00                	adc    BYTE PTR [rax],al
    2182:	00 00                	add    BYTE PTR [rax],al
    2184:	fc                   	cld    
    2185:	00 00                	add    BYTE PTR [rax],al
    2187:	00 38                	add    BYTE PTR [rax],bh
    2189:	f2 ff                	repnz (bad) 
    218b:	ff 05 00 00 00 00    	inc    DWORD PTR [rip+0x0]        # 2191 <__GNU_EH_FRAME_HDR+0x151>
    2191:	00 00                	add    BYTE PTR [rax],al
	...

0000000000002194 <__FRAME_END__>:
    2194:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .init_array:

0000000000003d78 <__frame_dummy_init_array_entry>:
    3d78:	40 12 00             	adc    al,BYTE PTR [rax]
    3d7b:	00 00                	add    BYTE PTR [rax],al
    3d7d:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .fini_array:

0000000000003d80 <__do_global_dtors_aux_fini_array_entry>:
    3d80:	00 12                	add    BYTE PTR [rdx],dl
    3d82:	00 00                	add    BYTE PTR [rax],al
    3d84:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .dynamic:

0000000000003d88 <_DYNAMIC>:
    3d88:	01 00                	add    DWORD PTR [rax],eax
    3d8a:	00 00                	add    BYTE PTR [rax],al
    3d8c:	00 00                	add    BYTE PTR [rax],al
    3d8e:	00 00                	add    BYTE PTR [rax],al
    3d90:	01 00                	add    DWORD PTR [rax],eax
    3d92:	00 00                	add    BYTE PTR [rax],al
    3d94:	00 00                	add    BYTE PTR [rax],al
    3d96:	00 00                	add    BYTE PTR [rax],al
    3d98:	0c 00                	or     al,0x0
    3d9a:	00 00                	add    BYTE PTR [rax],al
    3d9c:	00 00                	add    BYTE PTR [rax],al
    3d9e:	00 00                	add    BYTE PTR [rax],al
    3da0:	00 10                	add    BYTE PTR [rax],dl
    3da2:	00 00                	add    BYTE PTR [rax],al
    3da4:	00 00                	add    BYTE PTR [rax],al
    3da6:	00 00                	add    BYTE PTR [rax],al
    3da8:	0d 00 00 00 00       	or     eax,0x0
    3dad:	00 00                	add    BYTE PTR [rax],al
    3daf:	00 c8                	add    al,cl
    3db1:	13 00                	adc    eax,DWORD PTR [rax]
    3db3:	00 00                	add    BYTE PTR [rax],al
    3db5:	00 00                	add    BYTE PTR [rax],al
    3db7:	00 19                	add    BYTE PTR [rcx],bl
    3db9:	00 00                	add    BYTE PTR [rax],al
    3dbb:	00 00                	add    BYTE PTR [rax],al
    3dbd:	00 00                	add    BYTE PTR [rax],al
    3dbf:	00 78 3d             	add    BYTE PTR [rax+0x3d],bh
    3dc2:	00 00                	add    BYTE PTR [rax],al
    3dc4:	00 00                	add    BYTE PTR [rax],al
    3dc6:	00 00                	add    BYTE PTR [rax],al
    3dc8:	1b 00                	sbb    eax,DWORD PTR [rax]
    3dca:	00 00                	add    BYTE PTR [rax],al
    3dcc:	00 00                	add    BYTE PTR [rax],al
    3dce:	00 00                	add    BYTE PTR [rax],al
    3dd0:	08 00                	or     BYTE PTR [rax],al
    3dd2:	00 00                	add    BYTE PTR [rax],al
    3dd4:	00 00                	add    BYTE PTR [rax],al
    3dd6:	00 00                	add    BYTE PTR [rax],al
    3dd8:	1a 00                	sbb    al,BYTE PTR [rax]
    3dda:	00 00                	add    BYTE PTR [rax],al
    3ddc:	00 00                	add    BYTE PTR [rax],al
    3dde:	00 00                	add    BYTE PTR [rax],al
    3de0:	80 3d 00 00 00 00 00 	cmp    BYTE PTR [rip+0x0],0x0        # 3de7 <_DYNAMIC+0x5f>
    3de7:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
    3dea:	00 00                	add    BYTE PTR [rax],al
    3dec:	00 00                	add    BYTE PTR [rax],al
    3dee:	00 00                	add    BYTE PTR [rax],al
    3df0:	08 00                	or     BYTE PTR [rax],al
    3df2:	00 00                	add    BYTE PTR [rax],al
    3df4:	00 00                	add    BYTE PTR [rax],al
    3df6:	00 00                	add    BYTE PTR [rax],al
    3df8:	f5                   	cmc    
    3df9:	fe                   	(bad)  
    3dfa:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3dfd:	00 00                	add    BYTE PTR [rax],al
    3dff:	00 a0 03 00 00 00    	add    BYTE PTR [rax+0x3],ah
    3e05:	00 00                	add    BYTE PTR [rax],al
    3e07:	00 05 00 00 00 00    	add    BYTE PTR [rip+0x0],al        # 3e0d <_DYNAMIC+0x85>
    3e0d:	00 00                	add    BYTE PTR [rax],al
    3e0f:	00 68 05             	add    BYTE PTR [rax+0x5],ch
    3e12:	00 00                	add    BYTE PTR [rax],al
    3e14:	00 00                	add    BYTE PTR [rax],al
    3e16:	00 00                	add    BYTE PTR [rax],al
    3e18:	06                   	(bad)  
    3e19:	00 00                	add    BYTE PTR [rax],al
    3e1b:	00 00                	add    BYTE PTR [rax],al
    3e1d:	00 00                	add    BYTE PTR [rax],al
    3e1f:	00 d0                	add    al,dl
    3e21:	03 00                	add    eax,DWORD PTR [rax]
    3e23:	00 00                	add    BYTE PTR [rax],al
    3e25:	00 00                	add    BYTE PTR [rax],al
    3e27:	00 0a                	add    BYTE PTR [rdx],cl
    3e29:	00 00                	add    BYTE PTR [rax],al
    3e2b:	00 00                	add    BYTE PTR [rax],al
    3e2d:	00 00                	add    BYTE PTR [rax],al
    3e2f:	00 bd 00 00 00 00    	add    BYTE PTR [rbp+0x0],bh
    3e35:	00 00                	add    BYTE PTR [rax],al
    3e37:	00 0b                	add    BYTE PTR [rbx],cl
    3e39:	00 00                	add    BYTE PTR [rax],al
    3e3b:	00 00                	add    BYTE PTR [rax],al
    3e3d:	00 00                	add    BYTE PTR [rax],al
    3e3f:	00 18                	add    BYTE PTR [rax],bl
    3e41:	00 00                	add    BYTE PTR [rax],al
    3e43:	00 00                	add    BYTE PTR [rax],al
    3e45:	00 00                	add    BYTE PTR [rax],al
    3e47:	00 15 00 00 00 00    	add    BYTE PTR [rip+0x0],dl        # 3e4d <_DYNAMIC+0xc5>
	...
    3e55:	00 00                	add    BYTE PTR [rax],al
    3e57:	00 03                	add    BYTE PTR [rbx],al
    3e59:	00 00                	add    BYTE PTR [rax],al
    3e5b:	00 00                	add    BYTE PTR [rax],al
    3e5d:	00 00                	add    BYTE PTR [rax],al
    3e5f:	00 78 3f             	add    BYTE PTR [rax+0x3f],bh
    3e62:	00 00                	add    BYTE PTR [rax],al
    3e64:	00 00                	add    BYTE PTR [rax],al
    3e66:	00 00                	add    BYTE PTR [rax],al
    3e68:	02 00                	add    al,BYTE PTR [rax]
    3e6a:	00 00                	add    BYTE PTR [rax],al
    3e6c:	00 00                	add    BYTE PTR [rax],al
    3e6e:	00 00                	add    BYTE PTR [rax],al
    3e70:	d8 00                	fadd   DWORD PTR [rax]
    3e72:	00 00                	add    BYTE PTR [rax],al
    3e74:	00 00                	add    BYTE PTR [rax],al
    3e76:	00 00                	add    BYTE PTR [rax],al
    3e78:	14 00                	adc    al,0x0
    3e7a:	00 00                	add    BYTE PTR [rax],al
    3e7c:	00 00                	add    BYTE PTR [rax],al
    3e7e:	00 00                	add    BYTE PTR [rax],al
    3e80:	07                   	(bad)  
    3e81:	00 00                	add    BYTE PTR [rax],al
    3e83:	00 00                	add    BYTE PTR [rax],al
    3e85:	00 00                	add    BYTE PTR [rax],al
    3e87:	00 17                	add    BYTE PTR [rdi],dl
    3e89:	00 00                	add    BYTE PTR [rax],al
    3e8b:	00 00                	add    BYTE PTR [rax],al
    3e8d:	00 00                	add    BYTE PTR [rax],al
    3e8f:	00 58 07             	add    BYTE PTR [rax+0x7],bl
    3e92:	00 00                	add    BYTE PTR [rax],al
    3e94:	00 00                	add    BYTE PTR [rax],al
    3e96:	00 00                	add    BYTE PTR [rax],al
    3e98:	07                   	(bad)  
    3e99:	00 00                	add    BYTE PTR [rax],al
    3e9b:	00 00                	add    BYTE PTR [rax],al
    3e9d:	00 00                	add    BYTE PTR [rax],al
    3e9f:	00 68 06             	add    BYTE PTR [rax+0x6],ch
    3ea2:	00 00                	add    BYTE PTR [rax],al
    3ea4:	00 00                	add    BYTE PTR [rax],al
    3ea6:	00 00                	add    BYTE PTR [rax],al
    3ea8:	08 00                	or     BYTE PTR [rax],al
    3eaa:	00 00                	add    BYTE PTR [rax],al
    3eac:	00 00                	add    BYTE PTR [rax],al
    3eae:	00 00                	add    BYTE PTR [rax],al
    3eb0:	f0 00 00             	lock add BYTE PTR [rax],al
    3eb3:	00 00                	add    BYTE PTR [rax],al
    3eb5:	00 00                	add    BYTE PTR [rax],al
    3eb7:	00 09                	add    BYTE PTR [rcx],cl
    3eb9:	00 00                	add    BYTE PTR [rax],al
    3ebb:	00 00                	add    BYTE PTR [rax],al
    3ebd:	00 00                	add    BYTE PTR [rax],al
    3ebf:	00 18                	add    BYTE PTR [rax],bl
    3ec1:	00 00                	add    BYTE PTR [rax],al
    3ec3:	00 00                	add    BYTE PTR [rax],al
    3ec5:	00 00                	add    BYTE PTR [rax],al
    3ec7:	00 1e                	add    BYTE PTR [rsi],bl
    3ec9:	00 00                	add    BYTE PTR [rax],al
    3ecb:	00 00                	add    BYTE PTR [rax],al
    3ecd:	00 00                	add    BYTE PTR [rax],al
    3ecf:	00 08                	add    BYTE PTR [rax],cl
    3ed1:	00 00                	add    BYTE PTR [rax],al
    3ed3:	00 00                	add    BYTE PTR [rax],al
    3ed5:	00 00                	add    BYTE PTR [rax],al
    3ed7:	00 fb                	add    bl,bh
    3ed9:	ff                   	(bad)  
    3eda:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3edd:	00 00                	add    BYTE PTR [rax],al
    3edf:	00 01                	add    BYTE PTR [rcx],al
    3ee1:	00 00                	add    BYTE PTR [rax],al
    3ee3:	08 00                	or     BYTE PTR [rax],al
    3ee5:	00 00                	add    BYTE PTR [rax],al
    3ee7:	00 fe                	add    dh,bh
    3ee9:	ff                   	(bad)  
    3eea:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3eed:	00 00                	add    BYTE PTR [rax],al
    3eef:	00 48 06             	add    BYTE PTR [rax+0x6],cl
    3ef2:	00 00                	add    BYTE PTR [rax],al
    3ef4:	00 00                	add    BYTE PTR [rax],al
    3ef6:	00 00                	add    BYTE PTR [rax],al
    3ef8:	ff                   	(bad)  
    3ef9:	ff                   	(bad)  
    3efa:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3efd:	00 00                	add    BYTE PTR [rax],al
    3eff:	00 01                	add    BYTE PTR [rcx],al
    3f01:	00 00                	add    BYTE PTR [rax],al
    3f03:	00 00                	add    BYTE PTR [rax],al
    3f05:	00 00                	add    BYTE PTR [rax],al
    3f07:	00 f0                	add    al,dh
    3f09:	ff                   	(bad)  
    3f0a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3f0d:	00 00                	add    BYTE PTR [rax],al
    3f0f:	00 26                	add    BYTE PTR [rsi],ah
    3f11:	06                   	(bad)  
    3f12:	00 00                	add    BYTE PTR [rax],al
    3f14:	00 00                	add    BYTE PTR [rax],al
    3f16:	00 00                	add    BYTE PTR [rax],al
    3f18:	f9                   	stc    
    3f19:	ff                   	(bad)  
    3f1a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3f1d:	00 00                	add    BYTE PTR [rax],al
    3f1f:	00 03                	add    BYTE PTR [rbx],al
	...

Disassembly of section .got:

0000000000003f78 <_GLOBAL_OFFSET_TABLE_>:
    3f78:	88 3d 00 00 00 00    	mov    BYTE PTR [rip+0x0],bh        # 3f7e <_GLOBAL_OFFSET_TABLE_+0x6>
	...
    3f8e:	00 00                	add    BYTE PTR [rax],al
    3f90:	30 10                	xor    BYTE PTR [rax],dl
    3f92:	00 00                	add    BYTE PTR [rax],al
    3f94:	00 00                	add    BYTE PTR [rax],al
    3f96:	00 00                	add    BYTE PTR [rax],al
    3f98:	40 10 00             	adc    BYTE PTR [rax],al
    3f9b:	00 00                	add    BYTE PTR [rax],al
    3f9d:	00 00                	add    BYTE PTR [rax],al
    3f9f:	00 50 10             	add    BYTE PTR [rax+0x10],dl
    3fa2:	00 00                	add    BYTE PTR [rax],al
    3fa4:	00 00                	add    BYTE PTR [rax],al
    3fa6:	00 00                	add    BYTE PTR [rax],al
    3fa8:	60                   	(bad)  
    3fa9:	10 00                	adc    BYTE PTR [rax],al
    3fab:	00 00                	add    BYTE PTR [rax],al
    3fad:	00 00                	add    BYTE PTR [rax],al
    3faf:	00 70 10             	add    BYTE PTR [rax+0x10],dh
    3fb2:	00 00                	add    BYTE PTR [rax],al
    3fb4:	00 00                	add    BYTE PTR [rax],al
    3fb6:	00 00                	add    BYTE PTR [rax],al
    3fb8:	80 10 00             	adc    BYTE PTR [rax],0x0
    3fbb:	00 00                	add    BYTE PTR [rax],al
    3fbd:	00 00                	add    BYTE PTR [rax],al
    3fbf:	00 90 10 00 00 00    	add    BYTE PTR [rax+0x10],dl
    3fc5:	00 00                	add    BYTE PTR [rax],al
    3fc7:	00 a0 10 00 00 00    	add    BYTE PTR [rax+0x10],ah
    3fcd:	00 00                	add    BYTE PTR [rax],al
    3fcf:	00 b0 10 00 00 00    	add    BYTE PTR [rax+0x10],dh
	...

Disassembly of section .data:

0000000000004000 <__data_start>:
	...

0000000000004008 <__dso_handle>:
    4008:	08 40 00             	or     BYTE PTR [rax+0x0],al
    400b:	00 00                	add    BYTE PTR [rax],al
    400d:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .bss:

0000000000004010 <stdout@@GLIBC_2.2.5>:
	...

0000000000004020 <stdin@@GLIBC_2.2.5>:
	...

0000000000004028 <completed.8061>:
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp spl,BYTE PTR [r8]
   5:	28 55 62             	sub    BYTE PTR [rbp+0x62],dl
   8:	75 6e                	jne    78 <_init-0xf88>
   a:	74 75                	je     81 <_init-0xf7f>
   c:	20 39                	and    BYTE PTR [rcx],bh
   e:	2e 34 2e             	cs xor al,0x2e
  11:	30 2d 31 75 62 75    	xor    BYTE PTR [rip+0x75627531],ch        # 75627548 <_end+0x75623518>
  17:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  18:	74 75                	je     8f <_init-0xf71>
  1a:	31 7e 32             	xor    DWORD PTR [rsi+0x32],edi
  1d:	30 2e                	xor    BYTE PTR [rsi],ch
  1f:	30 34 2e             	xor    BYTE PTR [rsi+rbp*1],dh
  22:	31 29                	xor    DWORD PTR [rcx],ebp
  24:	20 39                	and    BYTE PTR [rcx],bh
  26:	2e 34 2e             	cs xor al,0x2e
  29:	30 00                	xor    BYTE PTR [rax],al

Disassembly of section .debug_aranges:

0000000000000000 <.debug_aranges>:
   0:	2c 00                	sub    al,0x0
   2:	00 00                	add    BYTE PTR [rax],al
   4:	02 00                	add    al,BYTE PTR [rax]
   6:	00 00                	add    BYTE PTR [rax],al
   8:	00 00                	add    BYTE PTR [rax],al
   a:	08 00                	or     BYTE PTR [rax],al
   c:	00 00                	add    BYTE PTR [rax],al
   e:	00 00                	add    BYTE PTR [rax],al
  10:	49 12 00             	rex.WB adc al,BYTE PTR [r8]
  13:	00 00                	add    BYTE PTR [rax],al
  15:	00 00                	add    BYTE PTR [rax],al
  17:	00 fe                	add    dh,bh
	...

Disassembly of section .debug_info:

0000000000000000 <.debug_info>:
   0:	f4                   	hlt    
   1:	03 00                	add    eax,DWORD PTR [rax]
   3:	00 04 00             	add    BYTE PTR [rax+rax*1],al
   6:	00 00                	add    BYTE PTR [rax],al
   8:	00 00                	add    BYTE PTR [rax],al
   a:	08 01                	or     BYTE PTR [rcx],al
   c:	96                   	xchg   esi,eax
   d:	00 00                	add    BYTE PTR [rax],al
   f:	00 0c e7             	add    BYTE PTR [rdi+riz*8],cl
  12:	01 00                	add    DWORD PTR [rax],eax
  14:	00 3e                	add    BYTE PTR [rsi],bh
  16:	02 00                	add    al,BYTE PTR [rax]
  18:	00 49 12             	add    BYTE PTR [rcx+0x12],cl
  1b:	00 00                	add    BYTE PTR [rax],al
  1d:	00 00                	add    BYTE PTR [rax],al
  1f:	00 00                	add    BYTE PTR [rax],al
  21:	fe 00                	inc    BYTE PTR [rax]
	...
  2b:	00 00                	add    BYTE PTR [rax],al
  2d:	02 37                	add    dh,BYTE PTR [rdi]
  2f:	00 00                	add    BYTE PTR [rax],al
  31:	00 02                	add    BYTE PTR [rdx],al
  33:	d1 17                	rcl    DWORD PTR [rdi],1
  35:	39 00                	cmp    DWORD PTR [rax],eax
  37:	00 00                	add    BYTE PTR [rax],al
  39:	03 08                	add    ecx,DWORD PTR [rax]
  3b:	07                   	(bad)  
  3c:	8a 01                	mov    al,BYTE PTR [rcx]
  3e:	00 00                	add    BYTE PTR [rax],al
  40:	03 04 07             	add    eax,DWORD PTR [rdi+rax*1]
  43:	8f 01                	pop    QWORD PTR [rcx]
  45:	00 00                	add    BYTE PTR [rax],al
  47:	04 08                	add    al,0x8
  49:	03 01                	add    eax,DWORD PTR [rcx]
  4b:	08 77 01             	or     BYTE PTR [rdi+0x1],dh
  4e:	00 00                	add    BYTE PTR [rax],al
  50:	03 02                	add    eax,DWORD PTR [rdx]
  52:	07                   	(bad)  
  53:	f6 01 00             	test   BYTE PTR [rcx],0x0
  56:	00 03                	add    BYTE PTR [rbx],al
  58:	01 06                	add    DWORD PTR [rsi],eax
  5a:	79 01                	jns    5d <_init-0xfa3>
  5c:	00 00                	add    BYTE PTR [rax],al
  5e:	03 02                	add    eax,DWORD PTR [rdx]
  60:	05 2d 00 00 00       	add    eax,0x2d
  65:	05 04 05 69 6e       	add    eax,0x6e690504
  6a:	74 00                	je     6c <_init-0xf94>
  6c:	03 08                	add    ecx,DWORD PTR [rax]
  6e:	05 2b 01 00 00       	add    eax,0x12b
  73:	02 79 02             	add    bh,BYTE PTR [rcx+0x2]
  76:	00 00                	add    BYTE PTR [rax],al
  78:	03 98 19 6c 00 00    	add    ebx,DWORD PTR [rax+0x6c19]
  7e:	00 02                	add    BYTE PTR [rdx],al
  80:	17                   	(bad)  
  81:	02 00                	add    al,BYTE PTR [rax]
  83:	00 03                	add    BYTE PTR [rbx],al
  85:	99                   	cdq    
  86:	1b 6c 00 00          	sbb    ebp,DWORD PTR [rax+rax*1+0x0]
  8a:	00 06                	add    BYTE PTR [rsi],al
  8c:	08 91 00 00 00 03    	or     BYTE PTR [rcx+0x3000000],dl
  92:	01 06                	add    DWORD PTR [rsi],eax
  94:	80 01 00             	add    BYTE PTR [rcx],0x0
  97:	00 07                	add    BYTE PTR [rdi],al
  99:	91                   	xchg   ecx,eax
  9a:	00 00                	add    BYTE PTR [rax],al
  9c:	00 08                	add    BYTE PTR [rax],cl
  9e:	0e                   	(bad)  
  9f:	00 00                	add    BYTE PTR [rax],al
  a1:	00 d8                	add    al,bl
  a3:	04 31                	add    al,0x31
  a5:	08 24 02             	or     BYTE PTR [rdx+rax*1],ah
  a8:	00 00                	add    BYTE PTR [rax],al
  aa:	09 55 00             	or     DWORD PTR [rbp+0x0],edx
  ad:	00 00                	add    BYTE PTR [rax],al
  af:	04 33                	add    al,0x33
  b1:	07                   	(bad)  
  b2:	65 00 00             	add    BYTE PTR gs:[rax],al
  b5:	00 00                	add    BYTE PTR [rax],al
  b7:	09 e9                	or     ecx,ebp
  b9:	02 00                	add    al,BYTE PTR [rax]
  bb:	00 04 36             	add    BYTE PTR [rsi+rsi*1],al
  be:	09 8b 00 00 00 08    	or     DWORD PTR [rbx+0x8000000],ecx
  c4:	09 7c 00 00          	or     DWORD PTR [rax+rax*1+0x0],edi
  c8:	00 04 37             	add    BYTE PTR [rdi+rsi*1],al
  cb:	09 8b 00 00 00 10    	or     DWORD PTR [rbx+0x10000000],ecx
  d1:	09 ab 02 00 00 04    	or     DWORD PTR [rbx+0x4000002],ebp
  d7:	38 09                	cmp    BYTE PTR [rcx],cl
  d9:	8b 00                	mov    eax,DWORD PTR [rax]
  db:	00 00                	add    BYTE PTR [rax],al
  dd:	18 09                	sbb    BYTE PTR [rcx],cl
  df:	5c                   	pop    rsp
  e0:	01 00                	add    DWORD PTR [rax],eax
  e2:	00 04 39             	add    BYTE PTR [rcx+rdi*1],al
  e5:	09 8b 00 00 00 20    	or     DWORD PTR [rbx+0x20000000],ecx
  eb:	09 47 00             	or     DWORD PTR [rdi+0x0],eax
  ee:	00 00                	add    BYTE PTR [rax],al
  f0:	04 3a                	add    al,0x3a
  f2:	09 8b 00 00 00 28    	or     DWORD PTR [rbx+0x28000000],ecx
  f8:	09 09                	or     DWORD PTR [rcx],ecx
  fa:	02 00                	add    al,BYTE PTR [rax]
  fc:	00 04 3b             	add    BYTE PTR [rbx+rdi*1],al
  ff:	09 8b 00 00 00 30    	or     DWORD PTR [rbx+0x30000000],ecx
 105:	09 5c 00 00          	or     DWORD PTR [rax+rax*1+0x0],ebx
 109:	00 04 3c             	add    BYTE PTR [rsp+rdi*1],al
 10c:	09 8b 00 00 00 38    	or     DWORD PTR [rbx+0x38000000],ecx
 112:	09 c1                	or     ecx,eax
 114:	01 00                	add    DWORD PTR [rax],eax
 116:	00 04 3d 09 8b 00 00 	add    BYTE PTR [rdi*1+0x8b09],al
 11d:	00 40 09             	add    BYTE PTR [rax+0x9],al
 120:	c8 02 00 00          	enter  0x2,0x0
 124:	04 40                	add    al,0x40
 126:	09 8b 00 00 00 48    	or     DWORD PTR [rbx+0x48000000],ecx
 12c:	09 81 02 00 00 04    	or     DWORD PTR [rcx+0x4000002],eax
 132:	41 09 8b 00 00 00 50 	or     DWORD PTR [r11+0x50000000],ecx
 139:	09 20                	or     DWORD PTR [rax],esp
 13b:	00 00                	add    BYTE PTR [rax],al
 13d:	00 04 42             	add    BYTE PTR [rdx+rax*2],al
 140:	09 8b 00 00 00 58    	or     DWORD PTR [rbx+0x58000000],ecx
 146:	09 73 00             	or     DWORD PTR [rbx+0x0],esi
 149:	00 00                	add    BYTE PTR [rax],al
 14b:	04 44                	add    al,0x44
 14d:	16                   	(bad)  
 14e:	3d 02 00 00 60       	cmp    eax,0x60000002
 153:	09 29                	or     DWORD PTR [rcx],ebp
 155:	02 00                	add    al,BYTE PTR [rax]
 157:	00 04 46             	add    BYTE PTR [rsi+rax*2],al
 15a:	14 43                	adc    al,0x43
 15c:	02 00                	add    al,BYTE PTR [rax]
 15e:	00 68 09             	add    BYTE PTR [rax+0x9],ch
 161:	21 02                	and    DWORD PTR [rdx],eax
 163:	00 00                	add    BYTE PTR [rax],al
 165:	04 48                	add    al,0x48
 167:	07                   	(bad)  
 168:	65 00 00             	add    BYTE PTR gs:[rax],al
 16b:	00 70 09             	add    BYTE PTR [rax+0x9],dh
 16e:	97                   	xchg   edi,eax
 16f:	02 00                	add    al,BYTE PTR [rax]
 171:	00 04 49             	add    BYTE PTR [rcx+rcx*2],al
 174:	07                   	(bad)  
 175:	65 00 00             	add    BYTE PTR gs:[rax],al
 178:	00 74 09 6b          	add    BYTE PTR [rcx+rcx*1+0x6b],dh
 17c:	01 00                	add    DWORD PTR [rax],eax
 17e:	00 04 4a             	add    BYTE PTR [rdx+rcx*2],al
 181:	0b 73 00             	or     esi,DWORD PTR [rbx+0x0]
 184:	00 00                	add    BYTE PTR [rax],al
 186:	78 09                	js     191 <_init-0xe6f>
 188:	50                   	push   rax
 189:	01 00                	add    DWORD PTR [rax],eax
 18b:	00 04 4d 12 50 00 00 	add    BYTE PTR [rcx*2+0x5012],al
 192:	00 80 09 b9 02 00    	add    BYTE PTR [rax+0x2b909],al
 198:	00 04 4e             	add    BYTE PTR [rsi+rcx*2],al
 19b:	0f 57 00             	xorps  xmm0,XMMWORD PTR [rax]
 19e:	00 00                	add    BYTE PTR [rax],al
 1a0:	82                   	(bad)  
 1a1:	09 a7 01 00 00 04    	or     DWORD PTR [rdi+0x4000001],esp
 1a7:	4f 08 49 02          	rex.WRXB or BYTE PTR [r9+0x2],r9b
 1ab:	00 00                	add    BYTE PTR [rax],al
 1ad:	83 09 3f             	or     DWORD PTR [rcx],0x3f
 1b0:	01 00                	add    DWORD PTR [rax],eax
 1b2:	00 04 51             	add    BYTE PTR [rcx+rdx*2],al
 1b5:	0f 59 02             	mulps  xmm0,XMMWORD PTR [rdx]
 1b8:	00 00                	add    BYTE PTR [rax],al
 1ba:	88 09                	mov    BYTE PTR [rcx],cl
 1bc:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 1bd:	01 00                	add    DWORD PTR [rax],eax
 1bf:	00 04 59             	add    BYTE PTR [rcx+rbx*2],al
 1c2:	0d 7f 00 00 00       	or     eax,0x7f
 1c7:	90                   	nop
 1c8:	09 a2 02 00 00 04    	or     DWORD PTR [rdx+0x4000002],esp
 1ce:	5b                   	pop    rbx
 1cf:	17                   	(bad)  
 1d0:	64 02 00             	add    al,BYTE PTR fs:[rax]
 1d3:	00 98 09 33 02 00    	add    BYTE PTR [rax+0x23309],bl
 1d9:	00 04 5c             	add    BYTE PTR [rsp+rbx*2],al
 1dc:	19 6f 02             	sbb    DWORD PTR [rdi+0x2],ebp
 1df:	00 00                	add    BYTE PTR [rax],al
 1e1:	a0 09 d2 01 00 00 04 	movabs al,ds:0x145d04000001d209
 1e8:	5d 14 
 1ea:	43 02 00             	rex.XB add al,BYTE PTR [r8]
 1ed:	00 a8 09 89 00 00    	add    BYTE PTR [rax+0x8909],ch
 1f3:	00 04 5e             	add    BYTE PTR [rsi+rbx*2],al
 1f6:	09 47 00             	or     DWORD PTR [rdi+0x0],eax
 1f9:	00 00                	add    BYTE PTR [rax],al
 1fb:	b0 09                	mov    al,0x9
 1fd:	ef                   	out    dx,eax
 1fe:	01 00                	add    DWORD PTR [rax],eax
 200:	00 04 5f             	add    BYTE PTR [rdi+rbx*2],al
 203:	0a 2d 00 00 00 b8    	or     ch,BYTE PTR [rip+0xffffffffb8000000]        # ffffffffb8000209 <_end+0xffffffffb7ffc1d9>
 209:	09 73 02             	or     DWORD PTR [rbx+0x2],esi
 20c:	00 00                	add    BYTE PTR [rax],al
 20e:	04 60                	add    al,0x60
 210:	07                   	(bad)  
 211:	65 00 00             	add    BYTE PTR gs:[rax],al
 214:	00 c0                	add    al,al
 216:	09 b1 01 00 00 04    	or     DWORD PTR [rcx+0x4000001],esi
 21c:	62                   	(bad)  
 21d:	08 75 02             	or     BYTE PTR [rbp+0x2],dh
 220:	00 00                	add    BYTE PTR [rax],al
 222:	c4                   	(bad)  
 223:	00 02                	add    BYTE PTR [rdx],al
 225:	12 00                	adc    al,BYTE PTR [rax]
 227:	00 00                	add    BYTE PTR [rax],al
 229:	05 07 19 9d 00       	add    eax,0x9d1907
 22e:	00 00                	add    BYTE PTR [rax],al
 230:	0a fd                	or     bh,ch
 232:	02 00                	add    al,BYTE PTR [rax]
 234:	00 04 2b             	add    BYTE PTR [rbx+rbp*1],al
 237:	0e                   	(bad)  
 238:	0b 9c 01 00 00 06 08 	or     ebx,DWORD PTR [rcx+rax*1+0x8060000]
 23f:	38 02                	cmp    BYTE PTR [rdx],al
 241:	00 00                	add    BYTE PTR [rax],al
 243:	06                   	(bad)  
 244:	08 9d 00 00 00 0c    	or     BYTE PTR [rbp+0xc000000],bl
 24a:	91                   	xchg   ecx,eax
 24b:	00 00                	add    BYTE PTR [rax],al
 24d:	00 59 02             	add    BYTE PTR [rcx+0x2],bl
 250:	00 00                	add    BYTE PTR [rax],al
 252:	0d 39 00 00 00       	or     eax,0x39
 257:	00 00                	add    BYTE PTR [rax],al
 259:	06                   	(bad)  
 25a:	08 30                	or     BYTE PTR [rax],dh
 25c:	02 00                	add    al,BYTE PTR [rax]
 25e:	00 0b                	add    BYTE PTR [rbx],cl
 260:	9f                   	lahf   
 261:	02 00                	add    al,BYTE PTR [rax]
 263:	00 06                	add    BYTE PTR [rsi],al
 265:	08 5f 02             	or     BYTE PTR [rdi+0x2],bl
 268:	00 00                	add    BYTE PTR [rax],al
 26a:	0b 30                	or     esi,DWORD PTR [rax]
 26c:	02 00                	add    al,BYTE PTR [rax]
 26e:	00 06                	add    BYTE PTR [rsi],al
 270:	08 6a 02             	or     BYTE PTR [rdx+0x2],ch
 273:	00 00                	add    BYTE PTR [rax],al
 275:	0c 91                	or     al,0x91
 277:	00 00                	add    BYTE PTR [rax],al
 279:	00 85 02 00 00 0d    	add    BYTE PTR [rbp+0xd000002],al
 27f:	39 00                	cmp    DWORD PTR [rax],eax
 281:	00 00                	add    BYTE PTR [rax],al
 283:	13 00                	adc    eax,DWORD PTR [rax]
 285:	0e                   	(bad)  
 286:	91                   	xchg   ecx,eax
 287:	02 00                	add    al,BYTE PTR [rax]
 289:	00 06                	add    BYTE PTR [rsi],al
 28b:	89 0e                	mov    DWORD PTR [rsi],ecx
 28d:	91                   	xchg   ecx,eax
 28e:	02 00                	add    al,BYTE PTR [rax]
 290:	00 06                	add    BYTE PTR [rsi],al
 292:	08 24 02             	or     BYTE PTR [rdx+rax*1],ah
 295:	00 00                	add    BYTE PTR [rax],al
 297:	0e                   	(bad)  
 298:	f6 02 00             	test   BYTE PTR [rdx],0x0
 29b:	00 06                	add    BYTE PTR [rsi],al
 29d:	8a 0e                	mov    cl,BYTE PTR [rsi]
 29f:	91                   	xchg   ecx,eax
 2a0:	02 00                	add    al,BYTE PTR [rax]
 2a2:	00 0e                	add    BYTE PTR [rsi],cl
 2a4:	1f                   	(bad)  
 2a5:	01 00                	add    DWORD PTR [rax],eax
 2a7:	00 06                	add    BYTE PTR [rsi],al
 2a9:	8b 0e                	mov    ecx,DWORD PTR [rsi]
 2ab:	91                   	xchg   ecx,eax
 2ac:	02 00                	add    al,BYTE PTR [rax]
 2ae:	00 0e                	add    BYTE PTR [rsi],cl
 2b0:	17                   	(bad)  
 2b1:	00 00                	add    BYTE PTR [rax],al
 2b3:	00 07                	add    BYTE PTR [rdi],al
 2b5:	1a 0c 65 00 00 00 0c 	sbb    cl,BYTE PTR [riz*2+0xc000000]
 2bc:	d1 02                	rol    DWORD PTR [rdx],1
 2be:	00 00                	add    BYTE PTR [rax],al
 2c0:	c6 02 00             	mov    BYTE PTR [rdx],0x0
 2c3:	00 0f                	add    BYTE PTR [rdi],cl
 2c5:	00 07                	add    BYTE PTR [rdi],al
 2c7:	bb 02 00 00 06       	mov    ebx,0x6000002
 2cc:	08 98 00 00 00 07    	or     BYTE PTR [rax+0x7000000],bl
 2d2:	cb                   	retf   
 2d3:	02 00                	add    al,BYTE PTR [rax]
 2d5:	00 0e                	add    BYTE PTR [rsi],cl
 2d7:	d6                   	(bad)  
 2d8:	02 00                	add    al,BYTE PTR [rax]
 2da:	00 07                	add    BYTE PTR [rdi],al
 2dc:	1b 1a                	sbb    ebx,DWORD PTR [rdx]
 2de:	c6 02 00             	mov    BYTE PTR [rdx],0x0
 2e1:	00 03                	add    BYTE PTR [rbx],al
 2e3:	08 05 26 01 00 00    	or     BYTE PTR [rip+0x126],al        # 40f <_init-0xbf1>
 2e9:	03 08                	add    ecx,DWORD PTR [rax]
 2eb:	07                   	(bad)  
 2ec:	85 01                	test   DWORD PTR [rcx],eax
 2ee:	00 00                	add    BYTE PTR [rax],al
 2f0:	0c 8b                	or     al,0x8b
 2f2:	00 00                	add    BYTE PTR [rax],al
 2f4:	00 00                	add    BYTE PTR [rax],al
 2f6:	03 00                	add    eax,DWORD PTR [rax]
 2f8:	00 0d 39 00 00 00    	add    BYTE PTR [rip+0x39],cl        # 337 <_init-0xcc9>
 2fe:	01 00                	add    DWORD PTR [rax],eax
 300:	0e                   	(bad)  
 301:	3e 00 00             	add    BYTE PTR ds:[rax],al
 304:	00 08                	add    BYTE PTR [rax],cl
 306:	9f                   	lahf   
 307:	0e                   	(bad)  
 308:	f0 02 00             	lock add al,BYTE PTR [rax]
 30b:	00 0e                	add    BYTE PTR [rsi],cl
 30d:	45 01 00             	add    DWORD PTR [r8],r8d
 310:	00 08                	add    BYTE PTR [rax],cl
 312:	a0 0c 65 00 00 00 0e 	movabs al,ds:0x1340e000000650c
 319:	34 01 
 31b:	00 00                	add    BYTE PTR [rax],al
 31d:	08 a1 11 6c 00 00    	or     BYTE PTR [rcx+0x6c11],ah
 323:	00 0e                	add    BYTE PTR [rsi],cl
 325:	40 00 00             	add    BYTE PTR [rax],al
 328:	00 08                	add    BYTE PTR [rax],cl
 32a:	a6                   	cmps   BYTE PTR ds:[rsi],BYTE PTR es:[rdi]
 32b:	0e                   	(bad)  
 32c:	f0 02 00             	lock add al,BYTE PTR [rax]
 32f:	00 0e                	add    BYTE PTR [rsi],cl
 331:	47 01 00             	rex.RXB add DWORD PTR [r8],r8d
 334:	00 08                	add    BYTE PTR [rax],cl
 336:	ae                   	scas   al,BYTE PTR es:[rdi]
 337:	0c 65                	or     al,0x65
 339:	00 00                	add    BYTE PTR [rax],al
 33b:	00 0e                	add    BYTE PTR [rsi],cl
 33d:	36 01 00             	add    DWORD PTR ss:[rax],eax
 340:	00 08                	add    BYTE PTR [rax],cl
 342:	af                   	scas   eax,DWORD PTR es:[rdi]
 343:	11 6c 00 00          	adc    DWORD PTR [rax+rax*1+0x0],ebp
 347:	00 10                	add    BYTE PTR [rax],dl
 349:	69 00 00 00 09 1f    	imul   eax,DWORD PTR [rax],0x1f090000
 34f:	02 0f                	add    cl,BYTE PTR [rdi]
 351:	55                   	push   rbp
 352:	03 00                	add    eax,DWORD PTR [rax]
 354:	00 06                	add    BYTE PTR [rsi],al
 356:	08 8b 00 00 00 0e    	or     BYTE PTR [rbx+0xe000000],cl
 35c:	07                   	(bad)  
 35d:	00 00                	add    BYTE PTR [rax],al
 35f:	00 0a                	add    BYTE PTR [rdx],cl
 361:	24 0e                	and    al,0xe
 363:	8b 00                	mov    eax,DWORD PTR [rax]
 365:	00 00                	add    BYTE PTR [rax],al
 367:	0e                   	(bad)  
 368:	00 00                	add    BYTE PTR [rax],al
 36a:	00 00                	add    BYTE PTR [rax],al
 36c:	0a 32                	or     dh,BYTE PTR [rdx]
 36e:	0c 65                	or     al,0x65
 370:	00 00                	add    BYTE PTR [rax],al
 372:	00 0e                	add    BYTE PTR [rsi],cl
 374:	ba 01 00 00 0a       	mov    edx,0xa000001
 379:	37                   	(bad)  
 37a:	0c 65                	or     al,0x65
 37c:	00 00                	add    BYTE PTR [rax],al
 37e:	00 0e                	add    BYTE PTR [rsi],cl
 380:	e2 02                	loop   384 <_init-0xc7c>
 382:	00 00                	add    BYTE PTR [rax],al
 384:	0a 3b                	or     bh,BYTE PTR [rbx]
 386:	0c 65                	or     al,0x65
 388:	00 00                	add    BYTE PTR [rax],al
 38a:	00 11                	add    BYTE PTR [rcx],dl
 38c:	cd 01                	int    0x1
 38e:	00 00                	add    BYTE PTR [rax],al
 390:	01 07                	add    DWORD PTR [rdi],eax
 392:	05 65 00 00 00       	add    eax,0x65
 397:	49 12 00             	rex.WB adc al,BYTE PTR [r8]
 39a:	00 00                	add    BYTE PTR [rax],al
 39c:	00 00                	add    BYTE PTR [rax],al
 39e:	00 fe                	add    dh,bh
 3a0:	00 00                	add    BYTE PTR [rax],al
 3a2:	00 00                	add    BYTE PTR [rax],al
 3a4:	00 00                	add    BYTE PTR [rax],al
 3a6:	00 01                	add    BYTE PTR [rcx],al
 3a8:	9c                   	pushf  
 3a9:	eb 03                	jmp    3ae <_init-0xc52>
 3ab:	00 00                	add    BYTE PTR [rax],al
 3ad:	12 62 75             	adc    ah,BYTE PTR [rdx+0x75]
 3b0:	66 00 01             	data16 add BYTE PTR [rcx],al
 3b3:	08 07                	or     BYTE PTR [rdi],al
 3b5:	eb 03                	jmp    3ba <_init-0xc46>
 3b7:	00 00                	add    BYTE PTR [rax],al
 3b9:	02 91 40 13 e0 01    	add    dl,BYTE PTR [rcx+0x1e01340]
 3bf:	00 00                	add    BYTE PTR [rax],al
 3c1:	01 09                	add    DWORD PTR [rcx],ecx
 3c3:	06                   	(bad)  
 3c4:	65 00 00             	add    BYTE PTR gs:[rax],al
 3c7:	00 02                	add    BYTE PTR [rdx],al
 3c9:	91                   	xchg   ecx,eax
 3ca:	5c                   	pop    rsp
 3cb:	14 ea                	adc    al,0xea
 3cd:	12 00                	adc    al,BYTE PTR [rax]
 3cf:	00 00                	add    BYTE PTR [rax],al
 3d1:	00 00                	add    BYTE PTR [rax],al
 3d3:	00 51 00             	add    BYTE PTR [rcx+0x0],dl
 3d6:	00 00                	add    BYTE PTR [rax],al
 3d8:	00 00                	add    BYTE PTR [rax],al
 3da:	00 00                	add    BYTE PTR [rax],al
 3dc:	12 67 00             	adc    ah,BYTE PTR [rdi+0x0]
 3df:	01 11                	add    DWORD PTR [rcx],edx
 3e1:	08 65 00             	or     BYTE PTR [rbp+0x0],ah
 3e4:	00 00                	add    BYTE PTR [rax],al
 3e6:	02 91 58 00 00 15    	add    dl,BYTE PTR [rcx+0x15000058]
 3ec:	91                   	xchg   ecx,eax
 3ed:	00 00                	add    BYTE PTR [rax],al
 3ef:	00 0d 39 00 00 00    	add    BYTE PTR [rip+0x39],cl        # 42e <_init-0xbd2>
 3f5:	0f 00 00             	sldt   WORD PTR [rax]

Disassembly of section .debug_abbrev:

0000000000000000 <.debug_abbrev>:
   0:	01 11                	add    DWORD PTR [rcx],edx
   2:	01 25 0e 13 0b 03    	add    DWORD PTR [rip+0x30b130e],esp        # 30b1316 <_end+0x30ad2e6>
   8:	0e                   	(bad)  
   9:	1b 0e                	sbb    ecx,DWORD PTR [rsi]
   b:	11 01                	adc    DWORD PTR [rcx],eax
   d:	12 07                	adc    al,BYTE PTR [rdi]
   f:	10 17                	adc    BYTE PTR [rdi],dl
  11:	00 00                	add    BYTE PTR [rax],al
  13:	02 16                	add    dl,BYTE PTR [rsi]
  15:	00 03                	add    BYTE PTR [rbx],al
  17:	0e                   	(bad)  
  18:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  1a:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  1c:	39 0b                	cmp    DWORD PTR [rbx],ecx
  1e:	49 13 00             	adc    rax,QWORD PTR [r8]
  21:	00 03                	add    BYTE PTR [rbx],al
  23:	24 00                	and    al,0x0
  25:	0b 0b                	or     ecx,DWORD PTR [rbx]
  27:	3e 0b 03             	or     eax,DWORD PTR ds:[rbx]
  2a:	0e                   	(bad)  
  2b:	00 00                	add    BYTE PTR [rax],al
  2d:	04 0f                	add    al,0xf
  2f:	00 0b                	add    BYTE PTR [rbx],cl
  31:	0b 00                	or     eax,DWORD PTR [rax]
  33:	00 05 24 00 0b 0b    	add    BYTE PTR [rip+0xb0b0024],al        # b0b005d <_end+0xb0ac02d>
  39:	3e 0b 03             	or     eax,DWORD PTR ds:[rbx]
  3c:	08 00                	or     BYTE PTR [rax],al
  3e:	00 06                	add    BYTE PTR [rsi],al
  40:	0f 00 0b             	str    WORD PTR [rbx]
  43:	0b 49 13             	or     ecx,DWORD PTR [rcx+0x13]
  46:	00 00                	add    BYTE PTR [rax],al
  48:	07                   	(bad)  
  49:	26 00 49 13          	add    BYTE PTR es:[rcx+0x13],cl
  4d:	00 00                	add    BYTE PTR [rax],al
  4f:	08 13                	or     BYTE PTR [rbx],dl
  51:	01 03                	add    DWORD PTR [rbx],eax
  53:	0e                   	(bad)  
  54:	0b 0b                	or     ecx,DWORD PTR [rbx]
  56:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  58:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  5a:	39 0b                	cmp    DWORD PTR [rbx],ecx
  5c:	01 13                	add    DWORD PTR [rbx],edx
  5e:	00 00                	add    BYTE PTR [rax],al
  60:	09 0d 00 03 0e 3a    	or     DWORD PTR [rip+0x3a0e0300],ecx        # 3a0e0366 <_end+0x3a0dc336>
  66:	0b 3b                	or     edi,DWORD PTR [rbx]
  68:	0b 39                	or     edi,DWORD PTR [rcx]
  6a:	0b 49 13             	or     ecx,DWORD PTR [rcx+0x13]
  6d:	38 0b                	cmp    BYTE PTR [rbx],cl
  6f:	00 00                	add    BYTE PTR [rax],al
  71:	0a 16                	or     dl,BYTE PTR [rsi]
  73:	00 03                	add    BYTE PTR [rbx],al
  75:	0e                   	(bad)  
  76:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  78:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  7a:	39 0b                	cmp    DWORD PTR [rbx],ecx
  7c:	00 00                	add    BYTE PTR [rax],al
  7e:	0b 13                	or     edx,DWORD PTR [rbx]
  80:	00 03                	add    BYTE PTR [rbx],al
  82:	0e                   	(bad)  
  83:	3c 19                	cmp    al,0x19
  85:	00 00                	add    BYTE PTR [rax],al
  87:	0c 01                	or     al,0x1
  89:	01 49 13             	add    DWORD PTR [rcx+0x13],ecx
  8c:	01 13                	add    DWORD PTR [rbx],edx
  8e:	00 00                	add    BYTE PTR [rax],al
  90:	0d 21 00 49 13       	or     eax,0x13490021
  95:	2f                   	(bad)  
  96:	0b 00                	or     eax,DWORD PTR [rax]
  98:	00 0e                	add    BYTE PTR [rsi],cl
  9a:	34 00                	xor    al,0x0
  9c:	03 0e                	add    ecx,DWORD PTR [rsi]
  9e:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  a0:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  a2:	39 0b                	cmp    DWORD PTR [rbx],ecx
  a4:	49 13 3f             	adc    rdi,QWORD PTR [r15]
  a7:	19 3c 19             	sbb    DWORD PTR [rcx+rbx*1],edi
  aa:	00 00                	add    BYTE PTR [rax],al
  ac:	0f 21 00             	mov    rax,db0
  af:	00 00                	add    BYTE PTR [rax],al
  b1:	10 34 00             	adc    BYTE PTR [rax+rax*1],dh
  b4:	03 0e                	add    ecx,DWORD PTR [rsi]
  b6:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  b8:	3b 05 39 0b 49 13    	cmp    eax,DWORD PTR [rip+0x13490b39]        # 13490bf7 <_end+0x1348cbc7>
  be:	3f                   	(bad)  
  bf:	19 3c 19             	sbb    DWORD PTR [rcx+rbx*1],edi
  c2:	00 00                	add    BYTE PTR [rax],al
  c4:	11 2e                	adc    DWORD PTR [rsi],ebp
  c6:	01 3f                	add    DWORD PTR [rdi],edi
  c8:	19 03                	sbb    DWORD PTR [rbx],eax
  ca:	0e                   	(bad)  
  cb:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  cd:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  cf:	39 0b                	cmp    DWORD PTR [rbx],ecx
  d1:	49 13 11             	adc    rdx,QWORD PTR [r9]
  d4:	01 12                	add    DWORD PTR [rdx],edx
  d6:	07                   	(bad)  
  d7:	40 18 96 42 19 01 13 	sbb    BYTE PTR [rsi+0x13011942],dl
  de:	00 00                	add    BYTE PTR [rax],al
  e0:	12 34 00             	adc    dh,BYTE PTR [rax+rax*1]
  e3:	03 08                	add    ecx,DWORD PTR [rax]
  e5:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  e7:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  e9:	39 0b                	cmp    DWORD PTR [rbx],ecx
  eb:	49 13 02             	adc    rax,QWORD PTR [r10]
  ee:	18 00                	sbb    BYTE PTR [rax],al
  f0:	00 13                	add    BYTE PTR [rbx],dl
  f2:	34 00                	xor    al,0x0
  f4:	03 0e                	add    ecx,DWORD PTR [rsi]
  f6:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  f8:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  fa:	39 0b                	cmp    DWORD PTR [rbx],ecx
  fc:	49 13 02             	adc    rax,QWORD PTR [r10]
  ff:	18 00                	sbb    BYTE PTR [rax],al
 101:	00 14 0b             	add    BYTE PTR [rbx+rcx*1],dl
 104:	01 11                	add    DWORD PTR [rcx],edx
 106:	01 12                	add    DWORD PTR [rdx],edx
 108:	07                   	(bad)  
 109:	00 00                	add    BYTE PTR [rax],al
 10b:	15 01 01 49 13       	adc    eax,0x13490101
 110:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .debug_line:

0000000000000000 <.debug_line>:
   0:	69 01 00 00 03 00    	imul   eax,DWORD PTR [rcx],0x30000
   6:	14 01                	adc    al,0x1
   8:	00 00                	add    BYTE PTR [rax],al
   a:	01 01                	add    DWORD PTR [rcx],eax
   c:	fb                   	sti    
   d:	0e                   	(bad)  
   e:	0d 00 01 01 01       	or     eax,0x1010100
  13:	01 00                	add    DWORD PTR [rax],eax
  15:	00 00                	add    BYTE PTR [rax],al
  17:	01 00                	add    DWORD PTR [rax],eax
  19:	00 01                	add    BYTE PTR [rcx],al
  1b:	2f                   	(bad)  
  1c:	75 73                	jne    91 <_init-0xf6f>
  1e:	72 2f                	jb     4f <_init-0xfb1>
  20:	6c                   	ins    BYTE PTR es:[rdi],dx
  21:	69 62 2f 67 63 63 2f 	imul   esp,DWORD PTR [rdx+0x2f],0x2f636367
  28:	78 38                	js     62 <_init-0xf9e>
  2a:	36 5f                	ss pop rdi
  2c:	36 34 2d             	ss xor al,0x2d
  2f:	6c                   	ins    BYTE PTR es:[rdi],dx
  30:	69 6e 75 78 2d 67 6e 	imul   ebp,DWORD PTR [rsi+0x75],0x6e672d78
  37:	75 2f                	jne    68 <_init-0xf98>
  39:	39 2f                	cmp    DWORD PTR [rdi],ebp
  3b:	69 6e 63 6c 75 64 65 	imul   ebp,DWORD PTR [rsi+0x63],0x6564756c
  42:	00 2f                	add    BYTE PTR [rdi],ch
  44:	75 73                	jne    b9 <_init-0xf47>
  46:	72 2f                	jb     77 <_init-0xf89>
  48:	69 6e 63 6c 75 64 65 	imul   ebp,DWORD PTR [rsi+0x63],0x6564756c
  4f:	2f                   	(bad)  
  50:	78 38                	js     8a <_init-0xf76>
  52:	36 5f                	ss pop rdi
  54:	36 34 2d             	ss xor al,0x2d
  57:	6c                   	ins    BYTE PTR es:[rdi],dx
  58:	69 6e 75 78 2d 67 6e 	imul   ebp,DWORD PTR [rsi+0x75],0x6e672d78
  5f:	75 2f                	jne    90 <_init-0xf70>
  61:	62                   	(bad)  
  62:	69 74 73 00 2f 75 73 	imul   esi,DWORD PTR [rbx+rsi*2+0x0],0x7273752f
  69:	72 
  6a:	2f                   	(bad)  
  6b:	69 6e 63 6c 75 64 65 	imul   ebp,DWORD PTR [rsi+0x63],0x6564756c
  72:	2f                   	(bad)  
  73:	78 38                	js     ad <_init-0xf53>
  75:	36 5f                	ss pop rdi
  77:	36 34 2d             	ss xor al,0x2d
  7a:	6c                   	ins    BYTE PTR es:[rdi],dx
  7b:	69 6e 75 78 2d 67 6e 	imul   ebp,DWORD PTR [rsi+0x75],0x6e672d78
  82:	75 2f                	jne    b3 <_init-0xf4d>
  84:	62                   	(bad)  
  85:	69 74 73 2f 74 79 70 	imul   esi,DWORD PTR [rbx+rsi*2+0x2f],0x65707974
  8c:	65 
  8d:	73 00                	jae    8f <_init-0xf71>
  8f:	2f                   	(bad)  
  90:	75 73                	jne    105 <_init-0xefb>
  92:	72 2f                	jb     c3 <_init-0xf3d>
  94:	69 6e 63 6c 75 64 65 	imul   ebp,DWORD PTR [rsi+0x63],0x6564756c
  9b:	00 00                	add    BYTE PTR [rax],al
  9d:	67 75 65             	addr32 jne 105 <_init-0xefb>
  a0:	73 73                	jae    115 <_init-0xeeb>
  a2:	2e 63 00             	movsxd eax,DWORD PTR cs:[rax]
  a5:	00 00                	add    BYTE PTR [rax],al
  a7:	00 73 74             	add    BYTE PTR [rbx+0x74],dh
  aa:	64 64 65 66 2e 68 00 	fs fs gs cs pushw 0x100
  b1:	01 
  b2:	00 00                	add    BYTE PTR [rax],al
  b4:	74 79                	je     12f <_init-0xed1>
  b6:	70 65                	jo     11d <_init-0xee3>
  b8:	73 2e                	jae    e8 <_init-0xf18>
  ba:	68 00 02 00 00       	push   0x200
  bf:	73 74                	jae    135 <_init-0xecb>
  c1:	72 75                	jb     138 <_init-0xec8>
  c3:	63 74 5f 46          	movsxd esi,DWORD PTR [rdi+rbx*2+0x46]
  c7:	49                   	rex.WB
  c8:	4c                   	rex.WR
  c9:	45                   	rex.RB
  ca:	2e 68 00 03 00 00    	cs push 0x300
  d0:	46                   	rex.RX
  d1:	49                   	rex.WB
  d2:	4c                   	rex.WR
  d3:	45                   	rex.RB
  d4:	2e 68 00 03 00 00    	cs push 0x300
  da:	73 74                	jae    150 <_init-0xeb0>
  dc:	64 69 6f 2e 68 00 04 	imul   ebp,DWORD PTR fs:[rdi+0x2e],0x40068
  e3:	00 
  e4:	00 73 79             	add    BYTE PTR [rbx+0x79],dh
  e7:	73 5f                	jae    148 <_init-0xeb8>
  e9:	65 72 72             	gs jb  15e <_init-0xea2>
  ec:	6c                   	ins    BYTE PTR es:[rdi],dx
  ed:	69 73 74 2e 68 00 02 	imul   esi,DWORD PTR [rbx+0x74],0x200682e
  f4:	00 00                	add    BYTE PTR [rax],al
  f6:	74 69                	je     161 <_init-0xe9f>
  f8:	6d                   	ins    DWORD PTR es:[rdi],dx
  f9:	65 2e 68 00 04 00 00 	gs cs push 0x400
 100:	75 6e                	jne    170 <_init-0xe90>
 102:	69 73 74 64 2e 68 00 	imul   esi,DWORD PTR [rbx+0x74],0x682e64
 109:	04 00                	add    al,0x0
 10b:	00 67 65             	add    BYTE PTR [rdi+0x65],ah
 10e:	74 6f                	je     17f <_init-0xe81>
 110:	70 74                	jo     186 <_init-0xe7a>
 112:	5f                   	pop    rdi
 113:	63 6f 72             	movsxd ebp,DWORD PTR [rdi+0x72]
 116:	65 2e 68 00 02 00 00 	gs cs push 0x200
 11d:	00 05 0c 00 09 02    	add    BYTE PTR [rip+0x209000c],al        # 209012f <_end+0x208c0ff>
 123:	49 12 00             	rex.WB adc al,BYTE PTR [r8]
 126:	00 00                	add    BYTE PTR [rax],al
 128:	00 00                	add    BYTE PTR [rax],al
 12a:	00 18                	add    BYTE PTR [rax],bl
 12c:	05 02 cc 05 08       	add    eax,0x805cc02
 131:	08 c9                	or     cl,cl
 133:	05 10 9e 05 12       	add    eax,0x12059e10
 138:	2e 05 10 58 05 02    	cs add eax,0x2055810
 13e:	2e 05 0b 75 05 09    	cs add eax,0x905750b
 144:	58                   	pop    rax
 145:	05 02 02 29 14       	add    eax,0x14290202
 14a:	05 05 08 13 05       	add    eax,0x5130805
 14f:	04 08                	add    al,0x8
 151:	74 05                	je     158 <_init-0xea8>
 153:	0c 59                	or     al,0x59
 155:	05 08 08 58 05       	add    eax,0x5580808
 15a:	04 3d                	add    al,0x3d
 15c:	05 06 08 59 83       	add    eax,0x83590806
 161:	d8 05 09 be 05 01    	fadd   DWORD PTR [rip+0x105be09]        # 105bf70 <_end+0x1057f40>
 167:	59                   	pop    rcx
 168:	02 07                	add    al,BYTE PTR [rdi]
 16a:	00 01                	add    BYTE PTR [rcx],al
 16c:	01                   	.byte 0x1

Disassembly of section .debug_str:

0000000000000000 <.debug_str>:
   0:	6f                   	outs   dx,DWORD PTR ds:[rsi]
   1:	70 74                	jo     77 <_init-0xf89>
   3:	69 6e 64 00 6f 70 74 	imul   ebp,DWORD PTR [rsi+0x64],0x74706f00
   a:	61                   	(bad)  
   b:	72 67                	jb     74 <_init-0xf8c>
   d:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
  10:	4f 5f                	rex.WRXB pop r15
  12:	46                   	rex.RX
  13:	49                   	rex.WB
  14:	4c                   	rex.WR
  15:	45 00 73 79          	add    BYTE PTR [r11+0x79],r14b
  19:	73 5f                	jae    7a <_init-0xf86>
  1b:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  1c:	65 72 72             	gs jb  91 <_init-0xf6f>
  1f:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
  22:	4f 5f                	rex.WRXB pop r15
  24:	73 61                	jae    87 <_init-0xf79>
  26:	76 65                	jbe    8d <_init-0xf73>
  28:	5f                   	pop    rdi
  29:	65 6e                	outs   dx,BYTE PTR gs:[rsi]
  2b:	64 00 73 68          	add    BYTE PTR fs:[rbx+0x68],dh
  2f:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  30:	72 74                	jb     a6 <_init-0xf5a>
  32:	20 69 6e             	and    BYTE PTR [rcx+0x6e],ch
  35:	74 00                	je     37 <_init-0xfc9>
  37:	73 69                	jae    a2 <_init-0xf5e>
  39:	7a 65                	jp     a0 <_init-0xf60>
  3b:	5f                   	pop    rdi
  3c:	74 00                	je     3e <_init-0xfc2>
  3e:	5f                   	pop    rdi
  3f:	5f                   	pop    rdi
  40:	74 7a                	je     bc <_init-0xf44>
  42:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  43:	61                   	(bad)  
  44:	6d                   	ins    DWORD PTR es:[rdi],dx
  45:	65 00 5f 49          	add    BYTE PTR gs:[rdi+0x49],bl
  49:	4f 5f                	rex.WRXB pop r15
  4b:	77 72                	ja     bf <_init-0xf41>
  4d:	69 74 65 5f 70 74 72 	imul   esi,DWORD PTR [rbp+riz*2+0x5f],0x727470
  54:	00 
  55:	5f                   	pop    rdi
  56:	66 6c                	data16 ins BYTE PTR es:[rdi],dx
  58:	61                   	(bad)  
  59:	67 73 00             	addr32 jae 5c <_init-0xfa4>
  5c:	5f                   	pop    rdi
  5d:	49                   	rex.WB
  5e:	4f 5f                	rex.WRXB pop r15
  60:	62                   	(bad)  
  61:	75 66                	jne    c9 <_init-0xf37>
  63:	5f                   	pop    rdi
  64:	62 61                	(bad)  
  66:	73 65                	jae    cd <_init-0xf33>
  68:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
  6b:	65 6e                	outs   dx,BYTE PTR gs:[rsi]
  6d:	76 69                	jbe    d8 <_init-0xf28>
  6f:	72 6f                	jb     e0 <_init-0xf20>
  71:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  72:	00 5f 6d             	add    BYTE PTR [rdi+0x6d],bl
  75:	61                   	(bad)  
  76:	72 6b                	jb     e3 <_init-0xf1d>
  78:	65 72 73             	gs jb  ee <_init-0xf12>
  7b:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
  7e:	4f 5f                	rex.WRXB pop r15
  80:	72 65                	jb     e7 <_init-0xf19>
  82:	61                   	(bad)  
  83:	64 5f                	fs pop rdi
  85:	65 6e                	outs   dx,BYTE PTR gs:[rsi]
  87:	64 00 5f 66          	add    BYTE PTR fs:[rdi+0x66],bl
  8b:	72 65                	jb     f2 <_init-0xf0e>
  8d:	65 72 65             	gs jb  f5 <_init-0xf0b>
  90:	73 5f                	jae    f1 <_init-0xf0f>
  92:	62                   	(bad)  
  93:	75 66                	jne    fb <_init-0xf05>
  95:	00 47 4e             	add    BYTE PTR [rdi+0x4e],al
  98:	55                   	push   rbp
  99:	20 43 31             	and    BYTE PTR [rbx+0x31],al
  9c:	37                   	(bad)  
  9d:	20 39                	and    BYTE PTR [rcx],bh
  9f:	2e 34 2e             	cs xor al,0x2e
  a2:	30 20                	xor    BYTE PTR [rax],ah
  a4:	2d 6d 74 75 6e       	sub    eax,0x6e75746d
  a9:	65 3d 67 65 6e 65    	gs cmp eax,0x656e6567
  af:	72 69                	jb     11a <_init-0xee6>
  b1:	63 20                	movsxd esp,DWORD PTR [rax]
  b3:	2d 6d 61 72 63       	sub    eax,0x6372616d
  b8:	68 3d 78 38 36       	push   0x3638783d
  bd:	2d 36 34 20 2d       	sub    eax,0x2d203436
  c2:	67 20 2d 66 6e 6f 2d 	and    BYTE PTR [eip+0x2d6f6e66],ch        # 2d6f6f2f <_end+0x2d6f2eff>
  c9:	73 74                	jae    13f <_init-0xec1>
  cb:	61                   	(bad)  
  cc:	63 6b 2d             	movsxd ebp,DWORD PTR [rbx+0x2d]
  cf:	70 72                	jo     143 <_init-0xebd>
  d1:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  d2:	74 65                	je     139 <_init-0xec7>
  d4:	63 74 6f 72          	movsxd esi,DWORD PTR [rdi+rbp*2+0x72]
  d8:	20 2d 66 61 73 79    	and    BYTE PTR [rip+0x79736166],ch        # 79736244 <_end+0x79732214>
  de:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  df:	63 68 72             	movsxd ebp,DWORD PTR [rax+0x72]
  e2:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  e3:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  e4:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  e5:	75 73                	jne    15a <_init-0xea6>
  e7:	2d 75 6e 77 69       	sub    eax,0x69776e75
  ec:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  ed:	64 2d 74 61 62 6c    	fs sub eax,0x6c626174
  f3:	65 73 20             	gs jae 116 <_init-0xeea>
  f6:	2d 66 73 74 61       	sub    eax,0x61747366
  fb:	63 6b 2d             	movsxd ebp,DWORD PTR [rbx+0x2d]
  fe:	63 6c 61 73          	movsxd ebp,DWORD PTR [rcx+riz*2+0x73]
 102:	68 2d 70 72 6f       	push   0x6f72702d
 107:	74 65                	je     16e <_init-0xe92>
 109:	63 74 69 6f          	movsxd esi,DWORD PTR [rcx+rbp*2+0x6f]
 10d:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 10e:	20 2d 66 63 66 2d    	and    BYTE PTR [rip+0x2d666366],ch        # 2d66647a <_end+0x2d66244a>
 114:	70 72                	jo     188 <_init-0xe78>
 116:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 117:	74 65                	je     17e <_init-0xe82>
 119:	63 74 69 6f          	movsxd esi,DWORD PTR [rcx+rbp*2+0x6f]
 11d:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 11e:	00 73 74             	add    BYTE PTR [rbx+0x74],dh
 121:	64 65 72 72          	fs gs jb 197 <_init-0xe69>
 125:	00 6c 6f 6e          	add    BYTE PTR [rdi+rbp*2+0x6e],ch
 129:	67 20 6c 6f 6e       	and    BYTE PTR [edi+ebp*2+0x6e],ch
 12e:	67 20 69 6e          	and    BYTE PTR [ecx+0x6e],ch
 132:	74 00                	je     134 <_init-0xecc>
 134:	5f                   	pop    rdi
 135:	5f                   	pop    rdi
 136:	74 69                	je     1a1 <_init-0xe5f>
 138:	6d                   	ins    DWORD PTR es:[rdi],dx
 139:	65 7a 6f             	gs jp  1ab <_init-0xe55>
 13c:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 13d:	65 00 5f 6c          	add    BYTE PTR gs:[rdi+0x6c],bl
 141:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 142:	63 6b 00             	movsxd ebp,DWORD PTR [rbx+0x0]
 145:	5f                   	pop    rdi
 146:	5f                   	pop    rdi
 147:	64 61                	fs (bad) 
 149:	79 6c                	jns    1b7 <_init-0xe49>
 14b:	69 67 68 74 00 5f 63 	imul   esp,DWORD PTR [rdi+0x68],0x635f0074
 152:	75 72                	jne    1c6 <_init-0xe3a>
 154:	5f                   	pop    rdi
 155:	63 6f 6c             	movsxd ebp,DWORD PTR [rdi+0x6c]
 158:	75 6d                	jne    1c7 <_init-0xe39>
 15a:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 15b:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
 15e:	4f 5f                	rex.WRXB pop r15
 160:	77 72                	ja     1d4 <_init-0xe2c>
 162:	69 74 65 5f 62 61 73 	imul   esi,DWORD PTR [rbp+riz*2+0x5f],0x65736162
 169:	65 
 16a:	00 5f 6f             	add    BYTE PTR [rdi+0x6f],bl
 16d:	6c                   	ins    BYTE PTR es:[rdi],dx
 16e:	64 5f                	fs pop rdi
 170:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 171:	66 66 73 65          	data16 data16 jae 1da <_init-0xe26>
 175:	74 00                	je     177 <_init-0xe89>
 177:	75 6e                	jne    1e7 <_init-0xe19>
 179:	73 69                	jae    1e4 <_init-0xe1c>
 17b:	67 6e                	outs   dx,BYTE PTR ds:[esi]
 17d:	65 64 20 63 68       	gs and BYTE PTR fs:[rbx+0x68],ah
 182:	61                   	(bad)  
 183:	72 00                	jb     185 <_init-0xe7b>
 185:	6c                   	ins    BYTE PTR es:[rdi],dx
 186:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 187:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 188:	67 20 6c 6f 6e       	and    BYTE PTR [edi+ebp*2+0x6e],ch
 18d:	67 20 75 6e          	and    BYTE PTR [ebp+0x6e],dh
 191:	73 69                	jae    1fc <_init-0xe04>
 193:	67 6e                	outs   dx,BYTE PTR ds:[esi]
 195:	65 64 20 69 6e       	gs and BYTE PTR fs:[rcx+0x6e],ch
 19a:	74 00                	je     19c <_init-0xe64>
 19c:	5f                   	pop    rdi
 19d:	49                   	rex.WB
 19e:	4f 5f                	rex.WRXB pop r15
 1a0:	6d                   	ins    DWORD PTR es:[rdi],dx
 1a1:	61                   	(bad)  
 1a2:	72 6b                	jb     20f <_init-0xdf1>
 1a4:	65 72 00             	gs jb  1a7 <_init-0xe59>
 1a7:	5f                   	pop    rdi
 1a8:	73 68                	jae    212 <_init-0xdee>
 1aa:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 1ab:	72 74                	jb     221 <_init-0xddf>
 1ad:	62                   	(bad)  
 1ae:	75 66                	jne    216 <_init-0xdea>
 1b0:	00 5f 75             	add    BYTE PTR [rdi+0x75],bl
 1b3:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 1b4:	75 73                	jne    229 <_init-0xdd7>
 1b6:	65 64 32 00          	gs xor al,BYTE PTR fs:[rax]
 1ba:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 1bb:	70 74                	jo     231 <_init-0xdcf>
 1bd:	65 72 72             	gs jb  232 <_init-0xdce>
 1c0:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
 1c3:	4f 5f                	rex.WRXB pop r15
 1c5:	62                   	(bad)  
 1c6:	75 66                	jne    22e <_init-0xdd2>
 1c8:	5f                   	pop    rdi
 1c9:	65 6e                	outs   dx,BYTE PTR gs:[rsi]
 1cb:	64 00 6d 61          	add    BYTE PTR fs:[rbp+0x61],ch
 1cf:	69 6e 00 5f 66 72 65 	imul   ebp,DWORD PTR [rsi+0x0],0x6572665f
 1d6:	65 72 65             	gs jb  23e <_init-0xdc2>
 1d9:	73 5f                	jae    23a <_init-0xdc6>
 1db:	6c                   	ins    BYTE PTR es:[rdi],dx
 1dc:	69 73 74 00 61 6e 73 	imul   esi,DWORD PTR [rbx+0x74],0x736e6100
 1e3:	77 65                	ja     24a <_init-0xdb6>
 1e5:	72 00                	jb     1e7 <_init-0xe19>
 1e7:	67 75 65             	addr32 jne 24f <_init-0xdb1>
 1ea:	73 73                	jae    25f <_init-0xda1>
 1ec:	2e 63 00             	movsxd eax,DWORD PTR cs:[rax]
 1ef:	5f                   	pop    rdi
 1f0:	5f                   	pop    rdi
 1f1:	70 61                	jo     254 <_init-0xdac>
 1f3:	64 35 00 73 68 6f    	fs xor eax,0x6f687300
 1f9:	72 74                	jb     26f <_init-0xd91>
 1fb:	20 75 6e             	and    BYTE PTR [rbp+0x6e],dh
 1fe:	73 69                	jae    269 <_init-0xd97>
 200:	67 6e                	outs   dx,BYTE PTR ds:[esi]
 202:	65 64 20 69 6e       	gs and BYTE PTR fs:[rcx+0x6e],ch
 207:	74 00                	je     209 <_init-0xdf7>
 209:	5f                   	pop    rdi
 20a:	49                   	rex.WB
 20b:	4f 5f                	rex.WRXB pop r15
 20d:	77 72                	ja     281 <_init-0xd7f>
 20f:	69 74 65 5f 65 6e 64 	imul   esi,DWORD PTR [rbp+riz*2+0x5f],0x646e65
 216:	00 
 217:	5f                   	pop    rdi
 218:	5f                   	pop    rdi
 219:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 21a:	66 66 36 34 5f       	data16 data16 ss xor al,0x5f
 21f:	74 00                	je     221 <_init-0xddf>
 221:	5f                   	pop    rdi
 222:	66 69 6c 65 6e 6f 00 	imul   bp,WORD PTR [rbp+riz*2+0x6e],0x6f
 229:	5f                   	pop    rdi
 22a:	63 68 61             	movsxd ebp,DWORD PTR [rax+0x61]
 22d:	69 6e 00 5f 49 4f 5f 	imul   ebp,DWORD PTR [rsi+0x0],0x5f4f495f
 234:	77 69                	ja     29f <_init-0xd61>
 236:	64 65 5f             	fs gs pop rdi
 239:	64 61                	fs (bad) 
 23b:	74 61                	je     29e <_init-0xd62>
 23d:	00 2f                	add    BYTE PTR [rdi],ch
 23f:	68 6f 6d 65 2f       	push   0x2f656d6f
 244:	77 65                	ja     2ab <_init-0xd55>
 246:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 247:	68 61 6f 31 2f       	push   0x2f316f61
 24c:	74 65                	je     2b3 <_init-0xd4d>
 24e:	73 74                	jae    2c4 <_init-0xd3c>
 250:	2f                   	(bad)  
 251:	64 61                	fs (bad) 
 253:	74 61                	je     2b6 <_init-0xd4a>
 255:	2f                   	(bad)  
 256:	68 6f 6d 65 2f       	push   0x2f656d6f
 25b:	74 6f                	je     2cc <_init-0xd34>
 25d:	6d                   	ins    DWORD PTR es:[rdi],dx
 25e:	6d                   	ins    DWORD PTR es:[rdi],dx
 25f:	79 2f                	jns    290 <_init-0xd70>
 261:	75 6e                	jne    2d1 <_init-0xd2f>
 263:	69 78 5f 70 72 6f 67 	imul   edi,DWORD PTR [rax+0x5f],0x676f7270
 26a:	2f                   	(bad)  
 26b:	70 72                	jo     2df <_init-0xd21>
 26d:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 26e:	63 65 6e             	movsxd esp,DWORD PTR [rbp+0x6e]
 271:	76 00                	jbe    273 <_init-0xd8d>
 273:	5f                   	pop    rdi
 274:	6d                   	ins    DWORD PTR es:[rdi],dx
 275:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 276:	64 65 00 5f 5f       	fs add BYTE PTR gs:[rdi+0x5f],bl
 27b:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 27c:	66 66 5f             	data16 pop di
 27f:	74 00                	je     281 <_init-0xd7f>
 281:	5f                   	pop    rdi
 282:	49                   	rex.WB
 283:	4f 5f                	rex.WRXB pop r15
 285:	62 61                	(bad)  
 287:	63 6b 75             	movsxd ebp,DWORD PTR [rbx+0x75]
 28a:	70 5f                	jo     2eb <_init-0xd15>
 28c:	62 61                	(bad)  
 28e:	73 65                	jae    2f5 <_init-0xd0b>
 290:	00 73 74             	add    BYTE PTR [rbx+0x74],dh
 293:	64 69 6e 00 5f 66 6c 	imul   ebp,DWORD PTR fs:[rsi+0x0],0x616c665f
 29a:	61 
 29b:	67 73 32             	addr32 jae 2d0 <_init-0xd30>
 29e:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
 2a1:	4f 5f                	rex.WRXB pop r15
 2a3:	63 6f 64             	movsxd ebp,DWORD PTR [rdi+0x64]
 2a6:	65 63 76 74          	movsxd esi,DWORD PTR gs:[rsi+0x74]
 2aa:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
 2ad:	4f 5f                	rex.WRXB pop r15
 2af:	72 65                	jb     316 <_init-0xcea>
 2b1:	61                   	(bad)  
 2b2:	64 5f                	fs pop rdi
 2b4:	62 61                	(bad)  
 2b6:	73 65                	jae    31d <_init-0xce3>
 2b8:	00 5f 76             	add    BYTE PTR [rdi+0x76],bl
 2bb:	74 61                	je     31e <_init-0xce2>
 2bd:	62                   	(bad)  
 2be:	6c                   	ins    BYTE PTR es:[rdi],dx
 2bf:	65 5f                	gs pop rdi
 2c1:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 2c2:	66 66 73 65          	data16 data16 jae 32b <_init-0xcd5>
 2c6:	74 00                	je     2c8 <_init-0xd38>
 2c8:	5f                   	pop    rdi
 2c9:	49                   	rex.WB
 2ca:	4f 5f                	rex.WRXB pop r15
 2cc:	73 61                	jae    32f <_init-0xcd1>
 2ce:	76 65                	jbe    335 <_init-0xccb>
 2d0:	5f                   	pop    rdi
 2d1:	62 61                	(bad)  
 2d3:	73 65                	jae    33a <_init-0xcc6>
 2d5:	00 73 79             	add    BYTE PTR [rbx+0x79],dh
 2d8:	73 5f                	jae    339 <_init-0xcc7>
 2da:	65 72 72             	gs jb  34f <_init-0xcb1>
 2dd:	6c                   	ins    BYTE PTR es:[rdi],dx
 2de:	69 73 74 00 6f 70 74 	imul   esi,DWORD PTR [rbx+0x74],0x74706f00
 2e5:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 2e6:	70 74                	jo     35c <_init-0xca4>
 2e8:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
 2eb:	4f 5f                	rex.WRXB pop r15
 2ed:	72 65                	jb     354 <_init-0xcac>
 2ef:	61                   	(bad)  
 2f0:	64 5f                	fs pop rdi
 2f2:	70 74                	jo     368 <_init-0xc98>
 2f4:	72 00                	jb     2f6 <_init-0xd0a>
 2f6:	73 74                	jae    36c <_init-0xc94>
 2f8:	64 6f                	outs   dx,DWORD PTR fs:[rsi]
 2fa:	75 74                	jne    370 <_init-0xc90>
 2fc:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
 2ff:	4f 5f                	rex.WRXB pop r15
 301:	6c                   	ins    BYTE PTR es:[rdi],dx
 302:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 303:	63 6b 5f             	movsxd ebp,DWORD PTR [rbx+0x5f]
 306:	74 00                	je     308 <_init-0xcf8>
